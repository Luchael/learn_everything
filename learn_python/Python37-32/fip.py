from math import ceil, floor, sqrt
class Soinsu:
    #클래스 변수
    numbers = []
    
    #클래스 함수
    @classmethod
    def print(cls):
        for number in cls.numbers:
            print(str(number))
            
    #인스턴스 함수
    def __init__(self,n):
        self.__n=n
        Soinsu.numbers.append(self)

    #루트 n 이하의 소수 구하기
    def little_prime(self):
        w,a=[2],3
        while ceil(sqrt(int(self.__n)))>=a:
            b=2
            while(b<=ceil(sqrt(a))or b<=floor(sqrt(a))) and a%b!=0:
                if b==ceil(sqrt(a)) and a%b!=0:
                    w.append(a)
                b+=1
            a+=1
        return w

    #n 소인수분해 하기
    def divide_prime(self):
        g=self.little_prime()
        copy_n=int(self.__n)
        a=0
        c=[]
        while copy_n !=1 and a<len(g):
            count = 0
            while copy_n%g[a]==0:
                copy_n/=g[a]
                count+=1
            if count!=0:
                c.append("%d^%d" % (g[a], count))
            if copy_n == 1:
                break
            a+=1    
        if copy_n!=1:
            c.append("%d^1" % int(copy_n))
            if len(c)==1:
                c.append("1")
        return "*".join(map(str,c))

    #str() 을 쓸 때 작동
    def __str__(self):
        return "소인수분해 결과입니다.\n{}".format(\
            self.divide_prime())

    #게터
    @property
    def n(self):
        return self.__n

    #세터
    @n.setter
    def n(self,value):
        if value<=0 or value.isdecimal() == False:
            raise TypeError("소인수분해 할 숫자는 자연수(양의 정수)이어야 합니다.")
        self.__n=value

print(Soinsu(input("소인수분해할 숫자를 입력해주세요: ")))