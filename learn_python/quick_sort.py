import random
def quick_sort(a):
    n=len(a)
    if n<=1:
        return a
    last = a[-1]
    left=[]
    right=[]
    for i in range(0, n-1):
        if a[i]<=last:
            left.append(a[i])
        else:
            right.append(a[i])
        #print("\n\nleft\n", left, "\n\nright\n", right, "\n\n")
    return quick_sort(left)+[last]+quick_sort(right)
data=[]
for i in range(1, 100):
    g=random.randint(1, 300)
    data.append(g)
print(data)
print('-'*318)
print(quick_sort(data))
print()
print("정렬 완료!")