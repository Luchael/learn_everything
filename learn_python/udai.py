a, max, min, difference, q = 1, int(input("최댓값을 입력하여주세요: ")), 1, 0, 1
if max!=0:
    while a:
        difference = max-min+1
        q = max - round(difference/2)
        if q==max: q-=1
        elif q==min: q+=1
        print("예측한 수: {}".format(q))
        print("더 크면 음수, 더 작으면 양수, 같으면 0 을 입력해주세요.: ")
        a = int(input())
        if a>0:
            min = q
        else:
            max = q
        if max-min<=1:
            if a>0:
                print(max)
            else:
                print(min)
            break