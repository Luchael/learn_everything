number = float(input('자연수를 입력하세요:'))
if number > 0:
    if number % 2 == 0:
        print("당신이 입력한 숫자인 %s는 짝수입니다." % number)
    elif number % 2 == 1:
        print("당신이 입력한 숫자인 %s는 홀수입니다." % number)
    else:
        print("당신이 입력한 숫자인 %s는 자연수가 아닙니다." % number)
else:
    print("당신이 입력한 숫자인 %s는 자연수가 아닙니다." % number)
