def sorting(arr):
    q, a = [], []
    for i in range(len(arr)):
        a.append(arr[i][0])
        q.append(arr[i][1])
    q.sort()
    b = []
    for i in range(len(q)):
        for j in range(len(a)):
            if [a[j], q[i]] in arr:
                b.append(arr[arr.index([a[j], q[i]])][0][0])
                a.pop(j)
                break
                
    return '→'.join(b)
list = []
for i in range(5):
    list.append(input().split(" # "))

list = sorting(list)
print('-'*50)
print(list)
print()