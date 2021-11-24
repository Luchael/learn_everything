#include <stdio.h>
#include <stdlib.h>

int main(void){
    char c;
    printf("---1번 문제---\n");
    printf("문자를 입력하시오: ");
    c=getchar();
    switch(c){
        case 'a':
        case 'i':
        case 'o':
        case 'u':
        case 'e':
            printf("모음입니다.");
            break;
        default :
            printf("자음입니다.");
            break;
    }

    printf("\n\n---2번 문제---\n");
    int x, y;
    printf("정수를 입력하시오: ");
    scanf("%d", &x);
    printf("정수를 입력하시오: ");
    scanf("%d", &y);
    if(!(x % y)) printf("약수입니다.");
    else printf("약수가 아닙니다.");

    printf("\n\n---3번 문제---\n");
    int num1, num2, num3, min;
    printf("3개의 정수를 입력하시오: ");
    scanf("%d%d%d", &num1, &num2, &num3);
    if(num1<=num2) min=num1;
    else min=num2;
    if(min<=num3) printf("제일 작은 정수는 %d입니다.", min);
    else printf("제일 작은 정수는 %d입니다.", num3);

    printf("\n\n---4번 문제---\n");
    int rsp, com;
    com=(rand()%3+1);
    printf("선택하시오(1: 가위 2: 바위 3: 보)");
    scanf("%d", &rsp);
    if(rsp==com) printf("비겼음");
    else if((rsp%3+1)==com)printf("컴퓨터가 이겼음");
    else printf("사용자가 이겼음");

    printf("\n\n---5번 문제---\n");
    int d, age;
    printf("키를 입력하시오(cm): ");
    scanf("%d", &d);
    printf("나이를 입력하시오: ");
    scanf("%d", &age);
    if(d>140 && age >= 10)printf("타도 좋습니다.");
    else printf("죄송합니다.");

    printf("\n\n---6번 문제---\n");
    int month;
    printf("월번호를 입력하시오: ");
    scanf("%d", &month);
    switch (month)
    {
    case 1:
        printf("Jan");
        break;
    case 2:
        printf("Feb");
        break;
    
    case 3:
        printf("Mar");
        break;
    case 4:
        printf("Apr");
        break;
    case 5:
        printf("May");
        break;
    case 6:
        printf("Jun");
        break;
    case 7:
        printf("Jul");
        break;
    case 8:
        printf("Aug");
        break;
    case 9:
        printf("Sep");
        break;
    case 10:
        printf("Oct");
        break;
    case 11:
        printf("Nov");
        break;
    case 12:
        printf("Dec");
        break;
    
    default:
        printf("존재하는 월번호를 입력해주세요");
        break;
    }

    printf("\n\n---7번 문제---\n");
    int height, weight;
    printf("체중과 키를 입력하세요: ");
    scanf("%d%d", &height, &weight);
    int BMI = (height-100)*0.9;
    if(BMI>weight) printf("저체중입니다.");
    else if(BMI==weight) printf("표준체중입니다.");
    else printf("과체중입니다.");

    printf("\n\n---8번 문제---\n");
    int time, old;
    printf("현재 시간과 나이를 입력하시오(시간, 나이): ");
    scanf("%d%d", &time, &old);
    if(old<3) printf("요금은 0입니다.");
    else if(time>=17)printf("요금은 10000입니다.");
    else if(old<=12 || old>=65) printf("요금은 25000입니다.");
    else printf("요금은 34000입니다.");
    
    printf("\n\n---9번 문제---\n");
    double q;
    printf("x의 값을 입력하시오:");
    scanf("%lf", &q);
    if(q<=0) q=q*q-9*q+2;
    else q=q*7+2;
    printf("f(x)의 값은 %lf", q);
    
    printf("\n\n---10번 문제---\n");
    int as, df;
    printf("좌표(x y): ");
    scanf("%d%d", &as, &df);
    if(as==0) printf("x축 위에 있다.");
    else if(df==0) printf("y축 위에 있다.");
    else if(as>0){
        if(df>0) printf("1사분면");
        else printf("4사분면");
    }
    else{
        if(df>0) printf("2사분면");
        else printf("3사분면");
    }

    printf("\n\n---11번 문제---\n");
    char hello;
    printf("문자를 입력하시오: ");
    scanf("%s", &hello);
    switch (hello)
    {
    case 'c':
    case 'C':
        printf("Circle");
        break;
    case 't':
    case 'T':
        printf("Triangle");
        break;
    case 'r':
    case 'R':
        printf("Ractangle");
        break;
    
    default:
        break;
    }

    return 0;
}