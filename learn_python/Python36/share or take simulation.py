import random
import math
def blue(vs):
    if vs=='':
        return ['blue',2]
    elif vs=='blue':
        return ['blue',1,'blue',1]
    elif vs=='red':
        return ['blue',0.5,'red',1.5]

def red(vs):
    if vs=='':
        return ['red',2]
    elif vs=='red':
        return ['red',0,'red',0]
    elif vs=='blue':
        return ['red',1.5,'blue',0.5]

def live(num):
    if num==0.5:
        num=random.randrange(0,2)
    if num==1.5:
        num=random.randrange(1,3)
    return num

blues=int(input('퍼랭이 마릿수 : '))
reds=int(input('빨갱이 마릿수 : '))
for i in range(10):
    food=100
    score=[]
    while food>0 and blues+reds>0:
        if blues==0:
            m='red'
        elif reds==0:
            m='blue'
        else:
            m=random.choice(['blue','red'])
        if m=='blue':
            if blues -1 == 0 and reds-1==-1:
                m=''
            elif blues -1 == 0 and reds-1>-1:
                m=random.choice(['red',''])
            elif blues-1>0 and reds-1==-1:
                m=random.choice(['blue',''])
            else:
                m=random.choice(['red','','blue'])
            if m=='blue':
                blues=blues-2
            elif m=='red':
                reds,blues=reds-1,blues-1
            else:
                blues=blues-1
        elif m=='red':
            if blues -1 == 0 and reds-1==-1:
                m=''
            elif blues -1 == 0 and reds-1>-1:
                m=random.choice(['red',''])
            elif blues-1>0 and reds-1==-1:
                m=random.choice(['blue',''])
            else:
                m=random.choice(['red','','blue'])
            if m=='blue':
                blues=blues-2
            elif m=='red':
                reds=reds-1
                blues=blues-1
            else:
                blues=blues-1
        food=food-2
    
    reds=0
    blues=0
    redl,bluel=[],[]
    for j in score:
        j.append('length')
        for k in range(j.index('length')):
            if j[k]=='red':
                redl.append(j[k+1])
            else:
                bluel.append(j[k+1])
            k=k+1
    for j in redl:
        reds+=live(j)
    for j in bluel:
        blues+=live(j)
    print(score)
    print('red: '+str(reds)+'\nblue: '+str(blues)+'\nblue-red: '+str(blues-reds))
            