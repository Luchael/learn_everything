#include <stdio.h>
#define PI 3.14159265358979323846264338
//*220쪽
int main()
{
    int m, n;
    printf("1번 문제\n2개의 정수를 입력하시오: ");
    scanf("%d%d", &m, &n);
    printf("몫: %d, 나머지: %d\n", m/n, m%n);

    double a, b;
    printf("2번 문제\n2개의 실수를 입력하시오: ");
    scanf("%lf%lf", &a, &b);
    printf("합: %lf\t차: %lf\t곱: %lf\t몫: %lf\t\n", a+b, a-b, a*b, a/b);

    int num1, num2, num3;
    printf("3번 문제\n3개의 정수를 입력하시오: ");
    scanf("%d%d%d", &num1, &num2, &num3);
    //! 참이 앞임
    printf("최대값: %d\n", num1>num2?(num1>num3?num1:num3):(num2>num3?num2:num3));

    int cenchimeter, feet;
    double inch;
    printf("4번 문제\n키를 입력하시오(cm): ");
    scanf("%d", &cenchimeter);
    inch = cenchimeter/2.54;
    feet = inch/12;
    inch -= feet*12;
    printf("%dcm는 %d피트 %lf인치입니다.\n", cenchimeter, feet, inch);

    int num;
    printf("5번 문제\n정수를 입력하시오: ");
    scanf("%d", &num);
    printf("십의 자리:%d\n일의 자리:%d\n", num/10, num%10);

    int number;
    printf("6번 문제\n정수를 입력하시오: ");
    scanf("%d", &number);
    printf("2의 보수: %d\n", ~number+1);

    int multiple2, times;
    printf("7번 문제\n정수를 입력하시오: ");
    scanf("%d", &multiple2);
    printf("2를 곱하고 싶은 횟수: ");
    scanf("%d", &times);
    printf("%d<<%d의 값: %d\n", multiple2, times, multiple2<<times);

    double radius;
    printf("8번 문제\n구의 반지름을 입력하십시오: ");
    scanf("%lf", &radius);
    printf("표면적은 %lf입니다.\n체적(부피)은 %lf입니다.\n", 4*PI*radius*radius, 4.0/3.0*PI*radius*radius*radius);

    double height, length, distance;
    printf("9번 문제\n지팡이의 높이를 입력하시오: ");
    scanf("%lf", &height);
    printf("지팡이 그림자의 길이를 입력하시오: ");
    scanf("%lf", &length);
    printf("피라미드까지의 거리를 입력하시오: ");
    scanf("%lf", &distance);
    printf("피라미드의 높이는 %lf입니다.\n", distance*(height/length));

    double x, y;
    printf("10번 문제\nx좌표를 입력하십시오: ");
    scanf("%lf", &x);
    printf("y좌표를 입력하십시오: ");
    scanf("%lf", &y);
    (x>0&&y>0)?printf("1사분면"): printf("");
    (x<0&&y>0)?printf("2사분면"): printf("");
    (x<0&&y<0)?printf("3사분면"): printf("");
    (x>0&&y<0)?printf("4사분면"): printf("");
    x==0?printf("y축 위에 있습니다."):printf("");
    y==0?printf("x축 위에 있습니다."):printf("");

    double how_far, degrees;
    printf("\n11번 문제\n거리를 입력하십시오 (km): ");
    scanf("%lf", &how_far);
    printf("각도를 입력하십시오: ");
    scanf("%lf", &degrees);
    printf("지구의 반지름은 %lfkm 입니다.\n", (how_far/degrees*360.0)/(PI*2.0));

    char q, w, e, r;
    printf("12번 문제\n첫번째 문자를 입력하십시오: ");
    scanf("%s", &q);
    printf("두번째 문자를 입력하십시오: ");
    scanf("%s", &w);
    printf("세번째 문자를 입력하십시오: ");
    scanf("%s", &e);
    printf("네번째 문자를 입력하십시오: ");
    scanf("%s", &r);
    printf("결과값: %x", (r<<24)|(e<<16)|(w<<8)|q);
    
    return 0;
}