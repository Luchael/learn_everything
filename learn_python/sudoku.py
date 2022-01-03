def input_make():

    grid=[]

    for i in range(9):

        lst=list(map(int, input("{}번째 줄을 입력하세요".format(i+1)).split(' ')))

        grid.append(lst)
    return grid


def possible(y,x,n,a,b,c):

    global grid
    if a:
        if x==y:
            for i in range(0,9):
                if grid[i][i] == n:
                    return False
        if x+y==8:
            for i in range(0,9):
                if grid[i][8-i]==n:
                    return False
    for i in range(0,9):

        if grid[y][i]==n:

            return False

    for i in range(0,9):

        if grid[i][x]==n:

            return False
    if c!=False:
        if c[0].count([y,x])!=0:
            if n%2==0: return False
        if c[1].count([y,x])!=0:
            if n%2==1: return False

    if b!=False:
        for i in b:
            if i.count([y,x])==1:
                for j in i:
                    if grid[j[0]][j[1]]==n:
                        return False
                break
    else:
        x0 = (x//3)*3

        y0 = (y//3)*3

        for i in range(0,3):

            for j in range(0,3):

                if grid [y0+i][x0+j]==n:

                    return False

    return True


def solve(i,a,b,c):

    global grid

    for y in range(i,9):

        for x in range(9):

            if grid[y][x]==0:

                for n in range(1,10):

                    if possible(y,x,n,a,b,c):

                        if grid[y][x]==0:

                            grid[y][x]=n

                            solve(y,a,b,c)

                            grid[y][x]=0

                return
    
    print('\n'.join(map(lambda x: ' '.join(map(str, x)), grid)))

    input("more?")


#main
while True:
    a = input("대각선 스도쿠입니까?(y/n)")
    if a=='y':
        a=True
        break
    if a=='n':
        a=False
        break
while True:
    b = input("직소 스도쿠(불규칙 스도쿠)입니까?(y/n) : ")
    if b=='y':
        b=[]
        for i in range(9):
            b.append(list(map(lambda x: list(map(int, x.split(","))), input("\n{}번 셀의 좌표를 입력해주세요(0,0 0,1 0,2...)\ny좌표 부터 입력해주세요\n: ".format(i+1)).split(" "))))
        break
    if b=='n':
        b=False
        break
while True:
    c = input("홀짝 스도쿠 입니까?(y/n) : ")
    if c=='y':
        c=[]
        c.append(list(map(lambda x: list(map(int, x.split(","))), input("\n홀수칸의 좌표를 입력하여주세요(0,0 5,1 3,2...)(없으면 q 입력)\ny좌표 부터 입력해주세요\n: ").split(" "))))
        c.append(list(map(lambda x: list(map(int, x.split(","))), input("\n짝수칸의 좌표를 입력하여주세요(0,0 5,1 3,2...)(없으면 q 입력)\ny좌표 부터 입력해주세요\n: ").split(" "))))
        break
    if c=='n':
        c=False
        break
grid=input_make()

print('\n'.join(map(lambda x: ' '.join(map(str, x)), solve(0,a,b,c))))