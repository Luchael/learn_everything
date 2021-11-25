#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct complex{double real, imag; };
typedef struct POINT{int x, y; }point;
typedef struct circle{
    point center;
    double radius;
}CIRCLE;

struct food{
    char name[200];
    int calories;
};

typedef struct EMPLOYEE{
    char name[20];
    int age;
}employee;

struct complex complex_add(struct complex c1, struct complex c2);
int equal(point *p1, point *p2);
int quadrant(point p);
double area(CIRCLE c), perimeter(CIRCLE c);

int main(){
    srand((unsigned)time(NULL));
    struct book{
        int id;
        char title[100];
        char author[20];
    };
    struct book ex1;
    printf("\n\n---1번 문제---\n");
    ex1.id = 1, strcpy(ex1.title, "바람과 함께 사라지다"), strcpy(ex1.author, "마가렛 미첼");
    printf("{ %d, %s, %s }", ex1.id, ex1.title, ex1.author);

    struct account{
        int number;
        char name[20];
        int balance;
    };
    struct account ex2;
    printf("\n\n---2번 문제---\n");
    ex2.number = 1, strcpy(ex2.name, "홍길동"), ex2.balance = 10000;
    printf("{ %d, %s, %d }", ex2.number, ex2.name, ex2.balance);

    struct mail{
        char title[50];
        char sender[43];
        char receiver[43];
        char content[150];
        char date[10];
        int rank;
    };
    struct mail ex3;
    printf("\n\n---3번 문제---\n");
    strcpy(ex3.title, "안부 메일"),strcpy(ex3.sender, "chulsoo@hankuk.ac.kr"),strcpy(ex3.receiver,"hsh@hankuk.ac.kr"),strcpy(ex3.content, "안녕하십니까? 별일 없으신지요?"),strcpy(ex3.date, "2010/9/1"),ex3.rank= 1;
    printf("제목: %s\n수신자: %s\n발신자:%s\n내용:%s\n날짜:%s\n우선순위%d\n", ex3.title, ex3.sender, ex3.receiver, ex3.content, ex3.date, ex3.rank);

    struct complex c1, c2;
    printf("\n\n---4번 문제---\n");
    scanf("%lf %lf %lf %lf", &c1.real, &c1.imag, &c2.real, &c2.imag);
    struct complex a = complex_add(c1, c2);
    printf("%g + %gi\n", a.real, a.imag);
    
    printf("\n\n---5, 6번 문제---\n");
    point p1, p2;
    printf("p1(x, y): ");
    scanf("%d %d", &p1.x, &p1.y);
    printf("p2(x, y): ");
    scanf("%d %d", &p2.x, &p2.y);
    printf("(%d, %d) %s (%d, %d)\n", p1.x, p1.y, equal(&p1, &p2)?"==":"!=", p2.x, p2.y);

    printf("\n\n---7번 문제---\n");
    point p3;
    printf("p3(x, y): ");
    scanf("%d %d", &p3.x, &p3.y);
    printf("(%d, %d)의 사분면 = %d", p3.x, p3.y, quadrant(p3));
    
    printf("\n\n---8번 (1), (2), (3)번 문제---\n");
    CIRCLE won;
    printf("원의 중심점: ");
    scanf("%d %d", &won.center.x, &won.center.y);
    printf("원의 반지름: ");
    scanf("%lf", &won.radius);
    printf("원의 면적 = %lf, 원의 둘레 = %lf", area(won), perimeter(won));

    printf("\n\n---9번 문제---\n");
    struct food food_array[3];

    printf("\n\n---10번 문제---\n");
    employee member[10];
    for(int i=0;i<10;i++){
        char a[10] = {"홍길동"};
        a[strlen(a)]=(char)i;
        strcpy(member[i].name, a);
        member[i].age = rand()%30+15;
    }
    for(int i=0;i<10;i++){
        if(member[i].age>20&&member[i].age<30)
            printf("이름=%s 나이=%d\n", member[i].name, member[i].age);
    }
}

struct complex complex_add(struct complex c1, struct complex c2){
    struct complex a = {c1.real+c2.real, c2.imag+c2.imag};
    return a;
}

int equal(point *p1, point *p2){
    if(p1->x==p2->x&&p2->y==p2->y) return 1;
    return 0;
}

int quadrant(point p){
    switch((p.x>0)+(p.y>0)){
        case 2: return 1;
        case 1: if(p.x>0) return 4;
                else return 2;
        case 0: return 3;
    }
}

double area(CIRCLE c){
    return c.radius*c.radius*3.14;
}

double perimeter(CIRCLE c){
    return c.radius*2*3.14;
}