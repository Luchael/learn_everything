# 시간
import time

#변수
number = 0
target = int(input("몇 초를 잴 것인지 입력하여주세요> "))

# 시간 설정
while number < target:
    print("{}시간 {}분 {}초".format(number//3600,number//60%60,number%60))
    time.sleep(target/target)
    number+=1

print("{}초가 지났습니다.".format(target))
