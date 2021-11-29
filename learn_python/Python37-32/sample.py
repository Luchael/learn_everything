numbers = [273,103,5,32,65,9,72,800,99]
for number in numbers:
    if number>100:
        print("- 100 이상의 수:", number)

print("---------------------------------------")

for number in numbers:
    if number%2==0:
        print(number,"는 짝수입니다.")
    else:
        print(number,"는 홀수입니다.")

print("---------------------------------------")
        
for number in numbers:
    print(number,"는 {}자릿수 입니다.".format(len(str(number))))

print("---------------------------------------")

list_of_list=[
    [1,2,3],
    [4,5,6,7],
    [8,9],
]

for i in list_of_list:
    for j in i:
        print(j)

print("---------------------------------------")

numbers=[1,2,3,4,5,6,7,8,9]
output = [[],[],[]]

for number in numbers:
    output[number%3-1].append(number)

print(output)

print("---------------------------------------")

dictionary = {
    "name": "7D 건조 망고",
    "type": "당절임",
    "ingredient": ["망고", '설탕', '메타중아황산나트륨', '치자황색소'],
    'origin': '필리핀'
    }

print('name:', dictionary['name'],"\ntype:",dictionary['type'],'\ningredient:',dictionary['ingredient'],'\norigin:',dictionary['origin'],'\n')

dictionary['name']='8D 건조 망고'
print('name:',dictionary['name'])

print("---------------------------------------")

# 메모 변수를 만듭니다.
dictionary = {
    1: 1,
    2: 2
}

# 함수를 선언합니다.
def fibonacci(n):
    if n in dictionary:
        # 메모가 되어 있으면 메모된 값을 리턴
        return dictionary[n]
    # 메모되어 있지 않으면 값을 구함
    output = fibonacci(n-1) + fibonacci(n - 2)
    dictionary[n] = output
    return output

a=print(fibonacci(int(input("피보나치 숫자 입력> "))))

print("---------------------------------------")

minimum=int(input("앉힐 수 있는 최소 사람 수 입력> "))
maximum=int(input("앉힐 수 있는 최대 사람 수 입력> "))
every=int(input("전체 사람의 수 입력> "))
memo={}

def problem(left,already):
    key=str([left, already])
    #종료 조건
    if key in memo:
        return memo[key]
    if left < 0:
        return 0            #무효이므로 0을 리턴
    if left ==0:
        return 1            #유효하므로 수를 세기 위해 1을 리턴
    #재귀처리
    count =0
    for i in range(already, maximum+1):
        count+=problem(left-i,i)
    #메모화 처리
    memo[key]=count
    #종료
    return count

print(problem(every,minimum))
