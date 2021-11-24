#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void get_sum_diff(int x, int y, int *p_sum, int *p_diff);
void array_fill(int *A, int size);
void array_print(int *A, int size);
void convert(double *grades, double *scores, int size);
void array_copy(int *A, int *B, int size);
void array_add(int *A, int *B, int*C, int size);
int array_sum(int *A, int size);
int search(int *A, int size, int search_value);
void get_lcm_gcd(int x, int y, int *p_lcm, int *p_gcd);
void merge(int *A, int *B, int *C, int size);
void get_int(int *px, int *py);

int main(void){
    srand((unsigned)time(NULL));
    /*printf("---1번 문제---\n");
    int xxxx = 0x12345678;
    unsigned char *xp = (char *)&xxxx;
    printf("바이트순서: %x %x %x %x\n", xp[0], xp[1], xp[2], xp[3]);
    
    */
    
    printf("\n---2번 문제---\n");
    int x=100, y=200, p_sum, p_diff;
    get_sum_diff(x, y, &p_sum, &p_diff);
    printf("원소들의 합=%d\n원소들의 차=%d\n", p_sum, p_diff);

    printf("\n---3번 문제---\n");
    int A[10];
    array_fill(A, 10);
    for(int i=0;i<10;i++)
        printf("%d ", A[i]);

    printf("\n\n---4번 문제---\n");
    array_print(A, 10);

    printf("\n---5번 문제---\n");
    double grades[10], scores[10];
    int i;
    for(i=0;i<9;i++){
        grades[i]=0.5*i;
        printf("%05.2lf ", grades[i]);
    }
    grades[9]=4.3;
    printf("04.30\n");
    convert(grades, scores, 10);
    for(i=0;i<10;i++){
        printf("%05.2lf ", scores[i]);
    }

    printf("\n\n---6번 문제---\n");
    int original_list[10], copy_list[10];
    for(i=0;i<10;i++)
        original_list[i]=i<3?i+1:0;
    array_copy(original_list, copy_list, 10);
    printf("A[] =");
    for(i=0;i<10;i++)
        printf(" %d", original_list[i]);
    printf("\nB[] =");
    for(i=0;i<10;i++)
        printf(" %d", copy_list[i]);
    
    printf("\n\n---7번 문제---\n");
    int base[10], bonus[10], pay[10];
    for(i=0;i<10;i++){
        base[i] = rand()%9+1;
    }
    for(i=0;i<10;i++){
        bonus[i] = rand()%4+1;
    }
    array_add(base, bonus, pay, 10);
    printf("A[] =");
    for(i=0;i<10;i++)
        printf(" %2d", base[i]);
    printf("\nB[] =");
    for(i=0;i<10;i++)
        printf(" %2d", bonus[i]);
    printf("\nC[] =");
    for(i=0;i<10;i++)
        printf(" %2d", pay[i]);
    
    printf("\n\n---8번 문제---\n");
    int pays[10];
    printf("A[] =");
    for(i=0;i<10;i++){
        pays[i] = i+1;
        printf(" %d", pays[i]);
    }
    printf("\n월급의 합=%d",array_sum(pays, 10));

    printf("\n\n---9번 문제---\n");
    int find_pay[10];
    for(i=0;i<10;i++)
        find_pay[i] = i+199;
    printf("월급이 200만원인 사람의 인덱스=%d", search(find_pay, 10, 200));

    printf("\n\n---10번 문제---\n");
    int num1, num2, lcm, gcd;
    printf("두개의 정수를 입력하시오: ");
    scanf("%d %d", &num1, &num2);
    get_lcm_gcd(num1, num2, &lcm, &gcd);
    printf("최소공배수는 %d입니다.\n최대공약수는 %d입니다.", lcm, gcd);

    printf("\n\n---11번 문제---\n");
    int list_A[5], list_B[5], list_C[10];
    printf("A[05] = ");
    for(i=0;i<5;i++)
        scanf(" %d", &list_A[i]); // A 입력
    printf("B[05] = ");
    for(i=0;i<5;i++)
        scanf(" %d", &list_B[i]); // B 입력
    merge(list_A, list_B, list_C, 10); 
    printf("C[10] =");
    for(i=0;i<10;i++)
        printf(" %d", list_C[i]); // 정리한거 출력
    
    printf("\n\n---12번 문제---\n");
    int px, py;
    printf("2개의 정수를 입력하시오(예: 10 20): ");
    scanf("%d %d", &px, &py);
    get_int(&px, &py);

    return 0;
}

void get_sum_diff(int x, int y, int *p_sum, int *p_diff){
    *p_sum = x+y, *p_diff = x-y;
}

void array_fill(int *A, int size){
    int i;
    for(i=0;i<size;i++){
        *(A+i)=rand();
    }
}

void array_print(int *A, int size){
    int i;
    printf("A[] = { ");
    for(i=0;i<size;i++){
        printf("%d ", *(A+i));
    }
    printf(" }\n");
}

void convert(double *grades, double *scores, int size){
    int i;
    for(i=0;i<size;i++){
        *(scores+i)=*(grades+i)*100/4.3;
    }
}

void array_copy(int *A, int *B, int size){
    int i;
    for(i=0;i<size;i++){
        *(B+i)=*(A+i);
    }
}

void array_add(int *A, int *B, int *C, int size){
    int i;
    for(i=0;i<size;i++){
        *(C+i) = *(A+i) + *(B+i);
    }
}

int array_sum(int *A, int size){
    int i, sum=0;
    for(i=0; i<size; i++){
        sum+=*(A+i);
    }
    return sum;
}

int search(int *A, int size, int search_value){
    int i;
    for(i=0;i<size;i++){
        if(A[i] == search_value)
            return i;
    }
}

void get_lcm_gcd(int x, int y, int *p_lcm, int *p_gcd){
    int mult = x*y;
    while (y!=0){
        int r = x%y;
        x = y;
        y = r;
    }
    *p_gcd = x, *p_lcm = mult/ *p_gcd;
}

void merge(int *A, int *B, int *C, int size){
    int a=0, b=0;
    for(int i=0;i<10;i++){
        //A의 인덱스를 넘어가면 B, B의 인덱스를 넘어가면 A, 둘 다 안 넘어가면 A[a]와 B[b]랑 비교, 더 작은 수를 넣고, 넣은 쪽 배열의 인덱스는 1 더함
        if(a>4) C[i] = B[b++];
        else if(b>4) C[i] = A[a++];
        else{
            if(A[a]>B[b])
                C[i] = B[b++];
            else
                C[i] = A[a++];
        }
        //*(C+i)=a>4?*(B+b):(b>4?*(A+a):(*(A+a)>*(B+b)?(b++, *(B+b-1)):(a++, *(A+a-1))));
    }
}

void get_int(int *px, int *py){
    printf("정수의 합은 %d", *px+*py);
}