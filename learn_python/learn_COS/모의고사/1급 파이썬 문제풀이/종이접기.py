# 다음과 같이 import를 사용할 수 있습니다.
# import math

def solution(garden):
    # 여기에 코드를 작성해주세요.
    answer = 0
    k = []
    while(len(garden)**2 == len(k)):
        for i in range(len(garden)):
            for j in range(len(garden)):
                if garden[i][j]:
                    k.append((i, j))    
        for i in k:
            if not (i[0], i[1]+1) in k:
                return answer

# 아래는 테스트케이스 출력을 해보기 위한 코드입니다.
garden1 = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]
ret1 = solution(garden1)

# [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
print("solution 함수의 반환 값은", ret1, "입니다.")

garden2 = [[1, 1], [1, 1]]
ret2 = solution(garden2)

# [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
print("solution 함수의 반환 값은", ret2, "입니다.")