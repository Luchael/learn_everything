import shutil

import tweepy
import os
import re
import string

import tensorflow as tf
import matplotlib.pyplot as plt
import numpy as np

import multiprocessing

from tensorflow.python.data.ops import dataset_ops
from tensorflow.python.ops import io_ops
from tensorflow.python.ops import string_ops
from tensorflow.python.util.tf_export import keras_export

from pathlib import Path


auth = tweepy.OAuthHandler(
    "bfpE4rzyOWKNa5D8ogiogCHAF", "oXZ0ZnwQgxPXyIQoMjpMbavwGRtS2B5lqFRAnkha3LsVrBBSWo"
)
auth.set_access_token(
    "905324212495122433-Ny0SL0txmsNqoiqSzdzj3PNuVeCENFP",
    "siffV0KTxdqrctkt1woD86VqFVXAl5tLm4KyZHompW8Uz"
)

api = tweepy.API(auth)
try:
    shutil.rmtree('datas')
    os.mkdir("datas")
    os.mkdir("datas/cat")
    os.mkdir("datas/dog")
except:
    os.mkdir("datas")
    os.mkdir("datas/cat")
    os.mkdir("datas/dog")

count = 0
limit = 10000
data_type = ""

print("Getting cat data")

data_type = "cat"

for tweet in tweepy.Cursor(
    api.search, q=f'{data_type}', lang="en", include_entitis=False, wait_on_rate_limit=True
).items():
    if count <= limit - 1:
        if "RT" not in tweet.text:
            out_file_dest = os.path.join(
                "datas", data_type, f'{count}.txt')
            out_file = open(out_file_dest, 'w')
            print(f'{data_type} Count #{count + 1}: {tweet.text}')
            out_file.write(tweet.text)
            out_file.close()
            count += 1
    else:
        break

count = 0

print("Getting dog data")

data_type = "dog"

for tweet in tweepy.Cursor(
    api.search, q=f'{data_type}', lang="en", include_entitis=False, wait_on_rate_limit=True
).items():
    if count <= limit - 1:
        if "RT" not in tweet.text:
            out_file_dest = os.path.join(
                "datas", data_type, f'{count}.txt')
            out_file = open(out_file_dest, 'w')
            print(f'{data_type} Count #{count + 1}: {tweet.text}')
            out_file.write(tweet.text)
            out_file.close()
            count += 1
    else:
        break

# 학습 시작
print("Start learning...")

# 원본: 텐서플로우 GitHub
# https://github.com/tensorflow/tensorflow/blob/master/tensorflow/python/keras/preprocessing/text_dataset.py


def index_directory(directory,
                    labels,
                    formats,
                    class_names=None,
                    shuffle=True,
                    seed=None,
                    follow_links=False):
    inferred_class_names = []
    for subdir in sorted(os.listdir(directory)):
        if os.path.isdir(os.path.join(directory, subdir)):
            inferred_class_names.append(subdir)
    if not class_names:
        class_names = inferred_class_names
    else:
        if set(class_names) != set(inferred_class_names):
            raise ValueError(
                'The `class_names` passed did not match the '
                'names of the subdirectories of the target directory. '
                'Expected: %s, but received: %s' %
                (inferred_class_names, class_names))
    class_indices = dict(zip(class_names, range(len(class_names))))

    pool = multiprocessing.pool.ThreadPool()
    results = []
    filenames = []
    for dirpath in (os.path.join(directory, subdir) for subdir in class_names):
        results.append(
            pool.apply_async(index_subdirectory,
                             (dirpath, class_indices, follow_links, formats)))
    labels_list = []
    for res in results:
        partial_filenames, partial_labels = res.get()
        labels_list.append(partial_labels)
        filenames += partial_filenames
    if labels != 'inferred':
        if len(labels) != len(filenames):
            raise ValueError('Expected the lengths of `labels` to match the number '
                             'of files in the target directory. len(labels) is %s '
                             'while we found %s files in %s.' % (
                                 len(labels), len(filenames), directory))
    else:
        i = 0
        labels = np.zeros((len(filenames),), dtype='int32')
        for partial_labels in labels_list:
            labels[i:i + len(partial_labels)] = partial_labels
            i += len(partial_labels)

    print('Found %d files belonging to %d classes.' %
          (len(filenames), len(class_names)))
    pool.close()
    pool.join()
    file_paths = [os.path.join(directory, fname) for fname in filenames]

    if shuffle:
        if seed is None:
            seed = np.random.randint(1e6)
        rng = np.random.RandomState(seed)
        rng.shuffle(file_paths)
        rng = np.random.RandomState(seed)
        rng.shuffle(labels)
    return file_paths, labels, class_names


def iter_valid_files(directory, follow_links, formats):
    walk = os.walk(directory, followlinks=follow_links)
    for root, _, files in sorted(walk, key=lambda x: x[0]):
        for fname in sorted(files):
            if fname.lower().endswith(formats):
                yield root, fname


def index_subdirectory(directory, class_indices, follow_links, formats):
    dirname = os.path.basename(directory)
    valid_files = iter_valid_files(directory, follow_links, formats)
    labels = []
    filenames = []
    for root, fname in valid_files:
        labels.append(class_indices[dirname])
        absolute_path = os.path.join(root, fname)
        relative_path = os.path.join(
            dirname, os.path.relpath(absolute_path, directory))
        filenames.append(relative_path)
    return filenames, labels


def check_validation_split_arg(validation_split, subset, shuffle, seed):
    if validation_split and not 0 < validation_split < 1:
        raise ValueError(
            '`validation_split` must be between 0 and 1, received: %s' %
            (validation_split,))
    if (validation_split or subset) and not (validation_split and subset):
        raise ValueError(
            'If `subset` is set, `validation_split` must be set, and inversely.')
    if subset not in ('training', 'validation', None):
        raise ValueError('`subset` must be either "training" '
                         'or "validation", received: %s' % (subset,))
    if validation_split and shuffle and seed is None:
        raise ValueError(
            'If using `validation_split` and shuffling the data, you must provide '
            'a `seed` argument, to make sure that there is no overlap between the '
            'training and validation subset.')


def get_training_or_validation_split(samples, labels, validation_split, subset):
    if not validation_split:
        return samples, labels

    num_val_samples = int(validation_split * len(samples))
    if subset == 'training':
        print('Using %d files for training.' %
              (len(samples) - num_val_samples,))
        samples = samples[:-num_val_samples]
        labels = labels[:-num_val_samples]
    elif subset == 'validation':
        print('Using %d files for validation.' % (num_val_samples,))
        samples = samples[-num_val_samples:]
        labels = labels[-num_val_samples:]
    else:
        raise ValueError('`subset` must be either "training" '
                         'or "validation", received: %s' % (subset,))
    return samples, labels


def labels_to_dataset(labels, label_mode, num_classes):
    label_ds = dataset_ops.Dataset.from_tensor_slices(labels)
    if label_mode == 'binary':
        label_ds = label_ds.map(
            lambda x: array_ops.expand_dims(math_ops.cast(x, 'float32'), axis=-1))
    elif label_mode == 'categorical':
        label_ds = label_ds.map(lambda x: array_ops.one_hot(x, num_classes))
    return label_ds


def paths_and_labels_to_dataset(file_paths,
                                labels,
                                label_mode,
                                num_classes,
                                max_length):
    path_ds = dataset_ops.Dataset.from_tensor_slices(file_paths)
    string_ds = path_ds.map(
        lambda x: path_to_string_content(x, max_length))
    if label_mode:
        label_ds = labels_to_dataset(labels, label_mode, num_classes)
        string_ds = dataset_ops.Dataset.zip((string_ds, label_ds))
    return string_ds


def path_to_string_content(path, max_length):
    txt = io_ops.read_file(path)
    if max_length is not None:
        txt = string_ops.substr(txt, 0, max_length)
    return txt


def text_dataset_from_directory(directory,
                                labels='inferred',
                                label_mode='int',
                                class_names=None,
                                batch_size=32,
                                max_length=None,
                                shuffle=True,
                                seed=None,
                                validation_split=None,
                                subset=None,
                                follow_links=False):
    if labels != 'inferred':
        if not isinstance(labels, (list, tuple)):
            raise ValueError(
                '`labels` argument should be a list/tuple of integer labels, of '
                'the same size as the number of text files in the target '
                'directory. If you wish to infer the labels from the subdirectory '
                'names in the target directory, pass `labels="inferred"`. '
                'If you wish to get a dataset that only contains text samples '
                '(no labels), pass `labels=None`.')
        if class_names:
            raise ValueError('You can only pass `class_names` if the labels are '
                             'inferred from the subdirectory names in the target '
                             'directory (`labels="inferred"`).')
    if label_mode not in {'int', 'categorical', 'binary', None}:
        raise ValueError(
            '`label_mode` argument must be one of "int", "categorical", "binary", '
            'or None. Received: %s' % (label_mode,))
    if seed is None:
        seed = np.random.randint(1e6)
    check_validation_split_arg(
        validation_split, subset, shuffle, seed)

    file_paths, labels, class_names = index_directory(
        directory,
        labels,
        formats=('.txt',),
        class_names=class_names,
        shuffle=shuffle,
        seed=seed,
        follow_links=follow_links)

    if label_mode == 'binary' and len(class_names) != 2:
        raise ValueError(
            'When passing `label_mode="binary", there must exactly 2 classes. '
            'Found the following classes: %s' % (class_names,))

    file_paths, labels = get_training_or_validation_split(
        file_paths, labels, validation_split, subset)

    dataset = paths_and_labels_to_dataset(
        file_paths=file_paths,
        labels=labels,
        label_mode=label_mode,
        num_classes=len(class_names),
        max_length=max_length)
    if shuffle:
        dataset = dataset.shuffle(buffer_size=batch_size * 8, seed=seed)
    dataset = dataset.batch(batch_size)
    dataset.class_names = class_names
    return dataset


# 진짜 코드 시작
print(f'Tensorflow 버전을 확인합니다: {tf.__version__}')

url = 'https://ai.stanford.edu/~amaas/data/sentiment/aclImdb_v1.tar.gz'
dataset = tf.keras.utils.get_file('aclImdb_v1.tar.gz', url,
                                  untar=True, cache_dir='.',
                                  cache_subdir='')
dataset_dir = os.path.join(os.path.dirname(dataset), 'aclImdb')
train_dir = os.path.join(dataset_dir, 'train')


pos_train_dir = os.path.join(train_dir, 'pos')
pos_train_files = os.listdir(pos_train_dir)
neg_train_dir = os.path.join(train_dir, 'neg')
neg_train_files = os.listdir(neg_train_dir)

remove_dir = os.path.join(train_dir, 'unsup')
print(f'불필요한 데이터 파일을 정리합니다. {remove_dir}')
shutil.rmtree(remove_dir)


batch_size = 32
validation_split = 0.2
seed = 20210701

print('학습 데이터 세트를 불러옵니다.')
raw_train_ds = text_dataset_from_directory(
    train_dir,
    batch_size=batch_size,
    validation_split=validation_split,
    subset='training',
    seed=seed)


print('검증 데이터 세트를 불러옵니다.')
raw_val_ds = text_dataset_from_directory(
    train_dir,
    batch_size=batch_size,
    validation_split=validation_split,
    subset='validation',
    seed=seed)


def custom_standardization(input_data):
    lowercase = tf.strings.lower(input_data)
    stripped_html = tf.strings.regex_replace(lowercase, '<br />', ' ')
    return tf.strings.regex_replace(stripped_html, '[%s]' % re.escape(string.punctuation), '')


max_features = 1000
sequence_length = 50

vectorize_layer = tf.keras.layers.experimental.preprocessing.TextVectorization(
    standardize=custom_standardization,
    max_tokens=max_features,
    output_mode='int',
    output_sequence_length=sequence_length)

print('테스트 데이터와 레이블을 분리합니다.')
train_text = raw_train_ds.map(lambda x, y: x)
vectorize_layer.adapt(train_text)


print('학습 완료 후 사용할 테스트 세트를 불러옵니다.')
test_dir = os.path.join(dataset_dir, 'test')
raw_test_ds = text_dataset_from_directory(
    test_dir,
    batch_size=batch_size)


def vectorize_text(text, label):
    text = tf.expand_dims(text, -1)
    return vectorize_layer(text), label


print('테스트 데이터를 확인합니다.')
text_batch, label_batch = next(iter(raw_train_ds))
first_review, first_label = text_batch[0], label_batch[0]
print("Review", first_review)
print("Label", raw_train_ds.class_names[first_label])
print("Vectorized review", vectorize_text(
    tf.expand_dims(first_review, -1), first_label))


print('학습, 검증, 테스트 데이터를 모두 벡터화 합니다.')
train_ds = raw_train_ds.map(vectorize_text)
val_ds = raw_val_ds.map(vectorize_text)
test_ds = raw_test_ds.map(vectorize_text)


AUTOTUNE = tf.data.experimental.AUTOTUNE
print('데이터 입력부를 최적화합니다.')
train_ds = train_ds.cache().prefetch(buffer_size=AUTOTUNE)
val_ds = val_ds.cache().prefetch(buffer_size=AUTOTUNE)
test_ds = test_ds.cache().prefetch(buffer_size=AUTOTUNE)


embedding_dim = 4

print('모델을 정의합니다.')
model = tf.keras.Sequential([
    tf.keras.layers.Embedding(max_features+1, embedding_dim, mask_zero=True),
    tf.keras.layers.Dropout(0.2),
    tf.keras.layers.GlobalAveragePooling1D(),
    tf.keras.layers.Dropout(0.2),
    tf.keras.layers.Dense(1)])

print(model.summary())


print('모델을 준비합니다.')
model.compile(loss=tf.keras.losses.BinaryCrossentropy(from_logits=True),
              optimizer='adam',
              metrics=tf.metrics.BinaryAccuracy(threshold=0.0))


epochs = 10
history = model.fit(
    train_ds,
    validation_data=val_ds,
    epochs=epochs)


print('모델 성능을 테스트합니다.')
loss, accuracy = model.evaluate(test_ds)

print("Loss: ", loss)
print("Accuracy: ", accuracy)

print('모델 출력')
export_model = tf.keras.Sequential([
    vectorize_layer,
    model,
    tf.keras.layers.Activation('sigmoid')
])

export_model.compile(
    loss=tf.keras.losses.BinaryCrossentropy(from_logits=False), optimizer="adam", metrics=['accuracy']
)

loss, accuracy = export_model.evaluate(raw_test_ds)
print(accuracy)

cat_pos = 0
cat_neg = 0
dog_pos = 0
dog_neg = 0

# cat
for p in Path('datas/cat').glob('*.txt'):
    data = p.read_text()
    predicted = export_model.predict(tf.expand_dims(data, -1))[0][0]
    result = raw_train_ds.class_names[int(round(predicted))]
    print(f'{result} ({predicted:0.4f})')
    if result == "pos":
        cat_pos += 1
    else:
        cat_neg += 1

# dog
for p in Path('datas/dog').glob('*.txt'):
    data = p.read_text()
    predicted = export_model.predict(tf.expand_dims(data, -1))[0][0]
    result = raw_train_ds.class_names[int(round(predicted))]
    print(f'{result} ({predicted:0.4f})')
    if result == "pos":
        dog_pos += 1
    else:
        dog_neg += 1


print(f'강아지의 긍정 반응: {dog_pos}')
print(f'강아지의 부정 반응: {dog_neg}')
print(f'고양이의 긍정 반응: {cat_pos}')
print(f'고양이의 부정 반응: {cat_neg}')

plt.pie([cat_pos, cat_neg], labels=["Positive for Cat",
                                    "Negative for Cat"], counterclock=False, autopct='%.1f%%')
plt.savefig('cat_pie.png', format='png', dpi=300)
plt.show()
plt.pie([dog_pos, dog_neg], labels=["Positive for Dog",
                                    "Negative for Dog"], counterclock=False, autopct='%.1f%%')
plt.savefig('dog_pie.png', format='png', dpi=300)
plt.show()
