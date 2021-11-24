#include <stdio.h>

int main(){
    double num1, num2, num3, sum;
    printf("1번 문제\n실수를 입력하시오: ");
    scanf("%lf", &num1);
    printf("실수를 입력하시오: ");
    scanf("%lf", &num2);
    printf("실수를 입력하시오: ");
    scanf("%lf", &num3);
    sum = num1+num2+num3;
    printf("합은 %lf이고 평균은 %lf입니다.\n", sum, sum/3);

    double mile;
    printf("2번 문제\n마일을 입력하시오: ");
    scanf("%lf", &mile);
    printf("%.1lf마일은 %lf미터입니다.\n", mile, 1609*mile);
    
    double height, base;
    printf("3번 문제\n삼각형의 밑변: ");
    scanf("%lf", &base);
    printf("삼각형의 높이: ");
    scanf("%lf", &height);
    printf("삼각형의 넓이: %lf\n", height*base*0.5);

    double f;
    printf("4번 문제\n화씨값을 입력하시오: ");
    scanf("%lf", &f);
    printf("섭씨값은 %lf도입니다.\n", 5.0/9*(f-32));

    double x;
    printf("5번 문제\n다항식 3x²+7x+11을 계산하세요!\n실수를 입력하세요: ");
    scanf("%lf", &x);
    printf("다항식의 값은 %lf\n", x*x*3+7*x+11);

    double weight_on_earth;
    printf("6번 문제\n몸무게를 입력하세요(단위: kg): ");
    scanf("%lf", &weight_on_earth);
    printf("달에서의 몸무게는 %lfkg입니다.", weight_on_earth*0.17);
}