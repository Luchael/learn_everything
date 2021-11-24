#define password 1234
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

double plus(double a, double b);
double multiple(double a, double b);
double divide(double a, double b);
double minus(double a, double b);
double remainder(double a, double b);
void get_dice_face(int a);
int check(int pass);
void get_random();
int sum(int n);
long long power(int base, int power_raised);
int show_digit(int x);
int get_digit_sum(int n);
int get_digit_length(int n);
double recursive(int n);
long long binomial_coefficient(int n, int k);
long long fib(int n);

double result = 0;
int main(){
    srand((unsigned int)time(NULL));
    printf("--1번 문제--\n");
    double a, b;
    char c;
    while(c!='='){
        printf("\n연산을 입력하시오: ");
        scanf("%lf %c %lf", &a, &c, &b);
        if(c=='+') a = plus(a, b);
        else if(c=='-') a = minus(a, b);
        else if(c=='*') a = multiple(a, b);
        else if(c=='/') a = divide(a, b);
        else if(c=='%') a = remainder(a, b);
        printf("연산 결과: %g\n", a);
    }

    printf("\n--2번 문제--\n\n");
    for(int i=0;i<100;i++)
        get_dice_face(rand()%6);
    
    printf("\n--3번 문제--\n\n");
    int pass;
    do{
        printf("비밀번호: ");
        scanf("%d", &pass);
    } while(!check(pass));

    printf("\n--4번 문제--\n\n");
    get_random();
    get_random();
    get_random();

    printf("\n--5번 문제--\n\n");
    int num;
    printf("정수를 입력하시오: ");
    scanf("%d", &num);
    printf("1부터 %d까지의 합=%d\n", num, sum(num));

    printf("\n--6번 문제--\n\n");
    int base, power_raised;
    printf("밑수: ");
    scanf("%d", &base);
    printf("지수: ");
    scanf("%d", &power_raised);
    printf("%d^%d = %lld\n", base, power_raised, power(base, power_raised));

    printf("\n--7번 문제--\n\n");
    int x;
    printf("정수를 입력하시오: ");
    scanf("%d", &x);
    printf("%d\n", show_digit(x));

    printf("\n\n--8번 문제--\n\n");
    int n;
    printf("정수를 입력하시오: ");
    scanf("%d", &n);
    printf("%d", get_digit_length(n));

    printf("\n\n--9번 문제--\n\n");
    printf("정수를 입력하시오: ");
    scanf("%d", &n);
    printf("자리수의 합: %d\n", get_digit_sum(n));

    printf("\n\n--10번 문제--\n\n");
    printf("정수를 입력하시오: ");
    scanf("%d", &n);
    printf("%g", recursive(n));

    printf("\n\n--11번 문제--\n\n");
    int k;
    printf("n=");
    scanf("%d", &n);
    printf("k=");
    scanf("%d", &k);
    printf("%lld", binomial_coefficient(n, k));

    printf("\n\n--12번 문제--\n\n");
    printf("정수를 입력하세요: ");
    scanf("%d", &n);
    for(int i=0;i<=n;i++)
        printf("fib(%d) = %lld\n", i, fib(i));
}

double plus(double a, double b){
    static int count = 0;
    count++;
    a+=b;
    printf("덧셈은 %d번 수행하였습니다.\n", count);
    return a;
}

double minus(double a, double b){
    static int count = 0;
    count++;
    a-=b;
    printf("뺄셈은 %d번 수행하였습니다.\n", count);
    return a;
}

double multiple(double a, double b){
    static int count = 0;
    count++;
    a*=b;
    printf("곱셈은 %d번 수행하였습니다.\n", count);
    return a;
}

double divide(double a, double b){
    static int count = 0;
    count++;
    a/=b;
    printf("곱셈은 %d번 수행하였습니다.\n", count);
    return a;
}

double remainder(double a, double b){
    static int count = 0;
    count++;
    a-=(int)(a/b)*b;
    printf("나머지연산은 %d번 수행하였습니다.\n", count);
    return a;
}

void get_dice_face(int a){
    static int count[7] = {0, 0, 0, 0, 0, 0, 0};
    count[a]++;
    count[6]++;
    if(count[6]==100)
        for(int i = 0;i<6;i++)
            printf("%d->%d\n", i+1, count[i]);
}

int check(int pass){
    static int count=0;
    if(pass==password) return 1;
    count++;
    if(count==3){
        printf("로그인 시도횟수 초과");
        return 2;
    }
    return 0;
}

void get_random(){
    static int inited = 0;
    if(!inited){
        inited++;
        srand((unsigned int)time(NULL));
        printf("초기화 실행\n");
    }
    printf("%d\n", rand());
}

int sum(int n){
    if(n==1) return 1;
    else return n+sum(n-1);
}

long long power(int base, int power_raised){
    if(power_raised==0) return 1;
    else return base*power(base, power_raised-1);
}

int show_digit(int x){
    if(x/10){
        printf("%d ", show_digit(x/10));
    }
    return x%10;
}

int get_digit_length(int n){
    if(n/10)
        return get_digit_length(n/10)+1;
    return 1;
}

int get_digit_sum(int n){
    if(n/10)
        return n%10+get_digit_sum(n/10);
    return n%10;
}

double recursive(int n) {
    if(n-1)
        return 1.0/n+recursive(n-1);
    return 1;
}

long long binomial_coefficient(int n, int k){
    if(n<k)
        n=k-n, k-=n, n+=k;
    if(k==n||k<=0)
        return 1;
    else
        return binomial_coefficient(n-1, k-1)+binomial_coefficient(n-1, k);
}

long long fib(int n){
    n = n<0?0:n;
    if(n<=1)
        return n;
    else
        return fib(n-2)+fib(n-1);
}