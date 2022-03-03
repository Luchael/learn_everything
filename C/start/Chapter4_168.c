#include <stdio.h>
#define SQMETER_PER_PYEONG 3.3058

int main(){
    double number;
    printf("1번 문제\n실수를 입력하시오: ");
    scanf("%lf", &number);
    printf("실수형식으로는 %lf입니다\n지수형식으로는 %e입니다\n", number, number);

    int hex;
    printf("2번문제\n16진수 정수를 입력하시오: ");
    scanf("%x", &hex);
    printf("8진수로는 %o입니다\n10진수로는 %d입니다\n16진수로는 %#x입니다\n", hex, hex, hex);

    int x=10, y=20, tmp;
    printf("3번 문제\nx와 y의 값을 서로 교환해보세요!\nx=%d\ty=%d\n", x, y);
    tmp=x, x=y, y=tmp;
    printf("x=%d\ty=%d\n", x, y);
    
    double w, h, d;
    printf("4번 문제\n상자의 가로 세로 높이를 한번에 입력: ");
    scanf("%lf%lf%lf", &w, &h, &d);
    printf("상자의 부피는 %lf입니다.\n", w*h*d);
    
    double pyeong;
    printf("5번 문제\n평을 입력하세요: ");
    scanf("%lf", &pyeong);
    printf("%lf평방미터입니다.\n", pyeong*SQMETER_PER_PYEONG);

    printf("6번 문제\n3.32×10⁻³+9.76×10⁻⁸\n");
    printf("%lf\n", 3.32e-3+9.76e-8);

    double mass, speed;
    printf("7번 문제\n질량(kg): ");
    scanf("%lf", &mass);
    printf("속도(m/s): ");
    scanf("%lf", &speed);
    printf("운동에너지(J): %lf\n", 1.0/2*mass*speed*speed);

    int str;
    printf("8번 문제\n아스키 코드값을 입력하시오: ");
    scanf("%d", &str);
    printf("문자: %c입니다.\n", str);

    printf("9번 문제\n%c%c%c\n", 'a'+1, 'a'+2, 'a'+3);

    printf("10번 문제\n\a화재가 발생하였습니다.");
    printf("\a\n");

    printf("11번 문제\n\"ASCII code\", 'A', 'B', 'C'\n\\t\t\\a\t\\n");
}