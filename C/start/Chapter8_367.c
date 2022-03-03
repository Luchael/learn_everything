#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define PI 3.141592653589793238462643388979
#define e 0.000001

double square(double a);
int check_alpha(char a);
double cal_area(double radius);
int is_leap(int year);
int round_num(double f);
int even(int n);
int absolute(int n);
int sign(int n);
int get_tax(int income);
double sin_degree(double degree);
int b_rand();
double f_rand();
void print_value(int n);
int is_multiple(int n, int m);
double get_distance(double x1, double y1, double x2, double y2);
int is_prime(int prime);
long long factorial(int n);
int f_equal(double a, double b);
double f_abs(double x);
double f_min(double x, double y);
int calculater(int p, int a, int b);

int main(){
    srand((unsigned int)time(NULL));
    printf("1번 문제\n");
    double x;
    printf("실수를 입력하시오: ");
    scanf("%lf", &x);
    printf("주어진 정수 %lf의 제곱은 %lf입니다.", x, square(x));

    printf("\n\n2번 문제\n");
    char ch;
    printf("문자를 입력하시오: ");
    scanf("\n%s", &ch);
    printf("%c는 %s니다.", ch, check_alpha(ch)?"알파벳 문자입":"알파벳 문자가 아닙");

    printf("\n\n3번 문제\n");
    double radius;
    printf("원의 반지름을 입력하시오: ");
    scanf("%lf", &radius);
    printf("원의 면적은 %lf입니다.", cal_area(radius));

    printf("\n\n4번 문제\n");
    int year;
    printf("연도를 입력하시오: ");
    scanf("%d", &year);
    printf("%d년은 %d일입니다.", year, is_leap(year));

    printf("\n\n5번 문제\n");
    double f;
    printf("실수를 입력하시오: ");
    scanf("%lf", &f);
    if(f>0) printf("반올림한 값은 %d입니다.", round_num(f));
    else printf("양수로 입력하여주세요.");

    printf("\n\n6번 문제\n");
    int num;
    printf("정수를 입력하시오: ");
    scanf("%d", &num);
    printf("even()의 결과: %s\nabsoluted()의 결과: %d\nsign()의 결과: %s", even(num)?"짝수":"홀수", absolute(num), sign(num)?(sign(num)>0?"양수":"음수"):"0");

    printf("\n\n7번 문제\n");
    int money;
    printf("소득을 입력하시오(만원): ");
    scanf("%d", &money);
    printf("소득세는 %d입니다.", get_tax(money));

    printf("\n\n8번 문제\n");
    double i;
    for(i=0;i<=180;i+=10){
        printf("sin(%lf)의 값은 %lf\n", i, sin_degree(i));
    }
    
    printf("\n\n9번 문제\n");
    int j;
    for(j=0;j<5;j++){
        printf("%d ", b_rand());
    }
    
    printf("\n\n10번 문제\n");
    int coin, YON;
    do{
        printf("앞면 또는 뒷면(1 또는 0): ");
        scanf("%d", &coin);
        printf("%s습니다.", b_rand()==coin?"맞았":"틀렸");
        do {
            printf("\n계속하시겟습니까?(y 또는 n): ");
            scanf("\n%c", &YON);
            if(YON=='n'||YON=='N'||YON=='y'||YON=='Y') break;
        }while(1);
        if(YON=='n'||YON=='N') break;
    } while(1);

    printf("\n\n11번 문제\n");
    for(i=0;i<5;i++){
        printf("%lf ", f_rand());
    }

    printf("\n\n12번 문제\n");
    int star;
    do{
        printf("값을 입력하시오(종료는 음수): ");
        scanf("%d", &star);
        print_value(star);
    } while(star>=0);

    printf("\n\n13번 문제\n");
    int n, m;
    printf("첫번째 정수를 입력하시오: ");
    scanf("%d", &n);
    printf("두번째 정수를 입력하시오: ");
    scanf("%d", &m);
    printf("%d는 %d의 %s니다.", n, m, is_multiple(n, m)?"배수":"배수가 아닙");

    printf("\n\n14번 문제\n");
    double x1, y1, x2, y2;
    printf("첫번째 점의 좌표를 입력하시오:(x, y)");
    scanf("%lf %lf", &x1, &y1);
    printf("두번째 점의 좌표를 입력하시오:(x, y)");
    scanf("%lf %lf", &x2, &y2);
    printf("두점 사이의 거리는 %lf입니다.", get_distance(x1, y1, x2, y2));

    printf("\n\n15번 문제\n");
    for(j=2;j<=100;j++){
        if(is_prime(j)){
            printf("%d ", j);
        }
    }

    printf("\n\n16번 문제\n");
    double result=1;
    int l;
    printf("어디까지 계산할까요: ");
    scanf("%d", &l);
    for(l;l>0;l--){
        result+=1.0/factorial(l);
    }
    printf("오일러의 수는 %lf입니다.", result);

    printf("\n\n17번 문제\n");
    double f1, f2;
    printf("실수를 입력하시오: ");
    scanf("%lf", &f1);
    printf("실수를 입력하시오: ");
    scanf("%lf", &f2);
    printf("두 개의 실수는 서로 %s", f_equal(f1, f2)?"같음":"다름");

    printf("\n\n18번 문제\n");
    int menu, num1, num2;
    char y;
    do{
        printf("==================================\nMENU\n==================================\n1. 덧셈\n2. 뺄셈\n3. 곱셈\n4. 나눗셈\n5. 나머지\n");
        printf("\n원하는 메뉴를 선택하시오(1-5):");
        scanf("%d", &menu);
        printf("숫자 2개를 입력하시오: ");
        scanf("%d %d", &num1, &num2);
        printf("연산결과 :%d", calculater(menu, num1, num2));
        printf("\n계속하려면 y를 누르시오: ");
        scanf("\n%c", &y);
    } while(y=='y'||y=='Y');
}

double square(double a){
    return a*a;
}

int check_alpha(char a){
    return (a>='A'&&a<='z');
}

double cal_area(double radius){
    return PI*radius*radius;
}

int is_leap(int year){
    return ((!(year%4))&&(year%100)||!(year%400))?366:365;
}

int round_num(double f){
    return (int)(f+0.5);
}

int even(int n){
    return !(n%2);
}
int absolute(int n){
    return n<0?-n:n;
}
int sign(int n){
    return n!=0?(n<0?-1:1):0;
}

int get_tax(int income){
    if(income<=1000) return income*0.08;
    return income*0.1;
}

double sin_degree(double degree){
    return sin(PI*degree/180);
}

int b_rand(){
    return rand()%2;
}

double f_rand(){
    return rand()/(double)RAND_MAX;
}

void print_value(int n){
    for(int i=0;i<n;i++){
        printf("*");
    }
    printf("\n");
}
int is_multiple(int n, int m){
    return !(n%m);
}
double get_distance(double x1, double y1, double x2, double y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
int is_prime(int prime){
    for(int i=prime-1;i>=2;i--){
        if(!(prime%i)) return 0;
    }
    return 1;
}
long long factorial(int n){
    long long result=1;
    for(n; n>0;n--){
        result*=n;
    }
    return result;
}
int f_equal(double a, double b){
    return (f_abs(a-b)/f_min(f_abs(a), f_abs(b)))<e;
}
double f_abs(double x){
    if(x>=0) return x;
    return -x;
}
double f_min(double x, double y){
    if(x>y) return y;
    return x;
}
int calculater(int p, int a, int b){
    return p==1?a+b:p==2?a-b:p==3?a*b:p==4?a/b:p==5?a%b:0;
}