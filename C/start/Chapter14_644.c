#include <stdio.h>
#include <string.h>

int get_sum_pointer(int *array[], int size);
int get_sum(int array[], int size);
void set_max_ptr(int m[], int size, int **pmax);
void sort_strings(char *list[], int size);

int main(){
    printf("---2번 문제---\n");
    int list[6] = {10,10,10,10,10,10};
    int* array[3] = {list, list, list};
    int sum = 0;
    printf("정수의 합 = %d\n", get_sum_pointer(array, 3));

    printf("\n---5번 문제---\n");
    int m[6] = {5, 6, 1, 3, 7, 9};
    int *pmax;  // 배열 m의 원소 중에서 가장 큰 값을 pmax가 가리킨다.

    set_max_ptr(m, 6, &pmax);
    printf("가장 큰 값은 %d\n", *pmax);

    printf("\n---6번 문제---\n");
    char* str[3] = {"mycopy", "src", "dst"};
    printf("원본\n%s\n%s\n%s\n", str[0], str[1], str[2]);
    sort_strings(str, 3);
    printf("정렬 후\n%s\n%s\n%s\n", str[0], str[1], str[2]);
    return 0;
}

int get_sum_pointer(int *array[], int size){
    int sum = 0;
    for(int i=0;i<size;i++){
        int k = get_sum(*(array+i), 6);
        sum += k;
        printf("%d번째 배열의 합 = %d\n", i, k);
    }
    return sum;
}
int get_sum(int array[], int size){
    int sum = 0;
    for(int i=0;i<size;i++){
        sum += *(array+i);
    }
    return sum;
}

void set_max_ptr(int m[], int size, int **pmax){
    *pmax = &*(m);
    for(int i=0;i<size;i++){
        *pmax = **pmax<*(m+i)?&*(m+i):*pmax;
    }
}

void sort_strings(char *list[], int size){
    int i, j, least;
    char *temp;

    for (i=0;i<size-1;i++){
        least = i;  // i번째 값을 최소값으로 가정
        for(j = i+1;j<size;j++)     //최소값 탐색
            if(strcmp(list[j], list[least])<0)
                least = j;
        // i번째 요소와 least 위치의 요소를 교환
        temp = list[i];
        list[i] = list[least];
        list[least] = temp;
    }
}