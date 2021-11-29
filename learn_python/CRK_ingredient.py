ingredient = ['나무','젤리','설탕','밀가루','베리','우유','양털']
product = {'도끼'   :['나무', 2],
           '곡괭이' :['나무',3,'설탕',3],
           '톱'     :['나무',6,'설탕',5],
           '삽'     :['나무',10,'설탕',10],
           '말뚝'   :['나무',15,'설탕',15],
           '파란잼' :['젤리',3],
           '빨간잼' :['젤리',6],
           '노란잼' :['젤리',6,'빵',2],
           '인형'   :['나무',6],
           '램프'   :['나무',12,'베리',3],
           '파이'   :['젤리',6,'밀가루',3],
           '빵'     :['파란잼',1,'밀가루',2],
           '스튜'   :['젤리',4,'베리',1],
           '크림'   :['빨간잼',1,'우유',2],
           '라떼'   :['젤리',12,'우유',2],
           '쿠션'   :['꽃',1,'양털',1],
           '행복'   :['설탕',10,'베리',4],
           '꽃'     :['베리',2,'화분',1],
           '화분'   :['인형',2,'밀가루',4],
           '유리'   :['설탕',12,'스튜',1]}

a = input("띄어쓰기 단위로 나눠서 입력 ㄱㄱ(예: 도끼 4 톱 7 나무 5) : ")
a = a.split(" ")
result = []
while(result != a):
    c=[]
    result = a
    for i in range(0, len(a), 2):
        a[i+1]=int(a[i+1])
        if a[i]=='노랑잼':
            a[i]='노란잼'
        elif a[i]=='파랑잼':
            a[i]='파란잼'
        elif a[i]=='빨강잼':
            a[i]='빨간잼'
        if(not(a[i] in ingredient)):
            g=product.get(a[i], 9)
            for j in range(1,len(g),2):
                g[j]=g[j]*a[i+1]
            a+=g
            c.append(i)
    c.reverse()
    for i in c:
        del a[i+1]
        del a[i]

how_many=[0,0,0,0,0,0,0]
for i in range(1,len(a),2):
    if a[i-1]=='나무':
        how_many[0]+=a[i]
    elif a[i-1]=='젤리':
        how_many[1]+=a[i]
    elif a[i-1]=='설탕':
        how_many[2]+=a[i]
    elif a[i-1]=='밀가루':
        how_many[3]+=a[i]
    elif a[i-1]=='베리':
        how_many[4]+=a[i]
    elif a[i-1]=='우유':
        how_many[5]+=a[i]
    elif a[i-1]=='양털':
        how_many[6]+=a[i]

a=list([v,str(v2)] for v, v2 in zip(ingredient,how_many))
for i in a:
    print('\t:   '.join(i))