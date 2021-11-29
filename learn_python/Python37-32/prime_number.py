from math import sqrt, ceil, floor

global prime
prime = []
global nprime
nprime = []

#소수인지 확인하는 함수
def isprime(n):
    #2의 배수면 처단
    if n!=2 and n%2==0:
        return False
    #이미 있던거면 바로 True
    if n in prime:
        return True
    #소수 아니라고 이미 판명 났으면 바로 False
    if n in nprime:
        return False
    #소수 판별
    number =2
    while sqrt(n)>=number:
        print("{}소수 판별 중".format(number))
        if isprime(number)==False:
            pass
        else:
            if n%number==0:
                nprime.append(n)
                return False

        """if n%number==0:
            nprime.append(n)
            return False"""
            
        number+=1
    prime.append(n)
    return True

def soinsu(n):
    print("soinsu({})".format(n))
    a, b = 0, []
    #메시지
    err="자연수로 입력해주세요."
    result = "소인수분해 결과입니다."
    #자연수인지 판별
    try:
        m=int(n)
        if m>0:
            aprime=little_prime(ceil(sqrt(m)))
            while m!=1 or a<(len(aprime)-1):
                count = 0
                ap=int(aprime[a])
                while m%ap==0:
                    count+=1
                    m/=ap
                if count!=0:
                    b.append(str(aprime[a])+"^"+str(count))
                a+=1
            return result+"*".join(map(str,b))
        else:
            return err
    except Exception as e:
        return str(type(e)) +'\t'+ str(e) + '\n'+err    

def thprime(n):
    w, a=["2"], 0
    #n번째
    while int(n)>len(w):
        b=2
        #2부터 올림(루트a) 까지 일일이 나눠보기
        while b<=ceil(sqrt(a)):
            #나머지가 0이면 반복문 빠져나오기
            if a%b==0:
                break
            #다 했는데 나머지가 0이 안 나오면 w 에다가 넣고 반복문 빠져나오기
            elif (ceil(sqrt(a))==b or floor(sqrt(a))==b) and a%b!=0:
                w.append(a)
                break
            #두 조건 만족 안 하면 1 올려서 시도
            b+=1
        #나누는 숫자 올리기
        a+=1
    return " ,".join(map(str,w))

def little_prime(n):
    w, a=["2"], 0
    #n보다 작거나 같음
    while int(n)>=int(w[len(w)-1]):
        b=2
        #2부터 올림(루트a) 까지 일일이 나눠보기
        while b<=ceil(sqrt(a)):
            #나머지가 0이면 반복문 빠져나오기
            if a%b==0:
                break
            #다 했는데 나머지가 0이 안 나오면 w 에다가 넣고 반복문 빠져나오기
            elif (ceil(sqrt(a))==b or floor(sqrt(a))==b) and a%b!=0:
                w.append(a)
                break
            #두 조건 만족 안 하면 1 올려서 시도
            b+=1
        #나누는 숫자 올리기
        a+=1
    return w


print(soinsu(input("소인수 분해를 할 숫자를 입력하세요> ")))