#include <stdio.h>
#include <windows.h>

int main(){

    system("chcp 65001");

    int i,n;
    printf("1번 문제\n");
    printf("카운터의 초기값을 입력하시오: "); 
    scanf("%d", &n);
    for(i=n;i>0;i--){
        printf("%d ", i);
    }
    printf("\a\n");

    int h, j=0;
    printf("2번 문제\n");
    for(h=1;h<=100;h++){
        if(h%3==0)j+=h;
    }
    printf("1부터 100 사이의 모든 3의 배수의 합은 %d입니다.\n", j);

    int k, l;
    printf("3번 문제\n");
    printf("정수를 입력하시오: ");
    scanf("%d", &k);
    printf("약수: ");
    for(l=1;l<=k;l++){
        if(k%l==0)printf("%d ", l);
    }

    int m, o;
    printf("\n4번 문제\n");
    for(m=1;m<=7;m++){
        for(o=6;o>=0;o--){
            if(o>=m)printf(" ");
            else printf("*");
        }
        printf("\n");
    }

    int p, q, r;
    printf("5번 문제\n");
    printf("정수를 입력하시오: ");
    scanf("%d", &p);
    for(q=1;q<=p;q++){
        for(r=1; r<=q;r++){
            printf("%d ", r);
        }
        printf("\n");
    }

    char op;
    int a, b;
    printf("6번 문제\n******************\nA---- Add\nS---- Subtract\nM---- Multiply\nD---- Divide\nQ---- Quit\n******************\n");
    do{
        printf("연산을 선택하시오: ");
        scanf("%s", &op);
        if(op=='Q')break;
        else if(!(op=='A'||op=='S'||op=='M'||op=='D'));
        else{
            printf("두수를 공백으로 분리하여 입력하시오: ");
            scanf("%d%d",&a,&b);
            printf("%d\n", op=='A'?a+b:op=='S'?a-b:op=='M'?a*b:a/b);
        }
    } while(1);

    int c, d;
    printf("7번 문제\n");
    for(c=2;c<=100;c++){
        for(d=2;d<=c;d++){
            if(d==c)printf("%d\t", c);
            else if(c%d==0)break;
        }
    }

    int e;
    printf("\n8번 문제\n");
    while(1){
        printf("막대의 높이(정수, 종료: -1, 최댓값: 50): ");
        scanf("%d", &e);
        if(e<=50&&e>=1){
            while(e!=0){
                printf("*");
                e--;
            }
            printf("\n");
        }
        else if(e==-1)break;
        else;
    }

    int f=1, g=0;
    printf("9번 문제\n");
    while(g<10000) g+=f++;
    f--;
    printf("1부터 %d까지의 합이 %d입니다.\n", --f, g-f);

    double s, s_1=1;
    int t;
    printf("10번 문제\n");
    printf("실수의 값을 입력하시오: ");
    scanf("%lf", &s);
    printf("거듭제곱횟수를 입력하시오: ");
    scanf("%d", &t);
    while(t>0)s_1*=s, t--;
    printf("결과값은 %lf\n", s_1);

    int u, v=1, w=0;
    printf("11번 문제\n");
    printf("n의 값을 입력하시오: ");
    scanf("%d", &u);
    while(v<=u)w+=v*v, v++;
    printf("계산값은 %d입니다.\n", w);

    int x, y=1, z=0;
    printf("12번 문제\n");
    printf("몇번째 항까지 구할까요? ");
    scanf("%d", &x);
    if(x>=0)printf("0");
    if(x>0) while(x!=1)z+=y, printf(", %d", z), y=z-y, x--;

    int num_n, num_r, num=1;
    printf("\n13번 문제\n");
    printf("n의 값: ");
    scanf("%d", &num_n);
    printf("\nr의 값: ");
    scanf("%d", &num_r);
    num_r=num_n-num_r++;
    for(num_n;num_n>=num_r+1;num_n--)num*=num_n;
    printf("순열의 값은 %d입니다.\n", num);

    int final;
    printf("14번 문제\n");
    printf("정수를 입력하시오: ");
    scanf("%d", &final);
    while(final!=0)printf("%d", final%10),final/=10;
}
