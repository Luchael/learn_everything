#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct address{
    char name[80];
    char number[80];
};

char *get_word();

int main(){
    printf("---1번 문제---\n");
    int size, sum=0;
    int *list;
    printf("정수의 개수: ");
    scanf("%d", &size);
    list = malloc(sizeof(int)*size);
    for(int i=0;i<size;i++){
        printf("양의 정수를 입력하시오:");
        scanf("%d", &list[i]);
        sum+=list[i];
    }
    printf("합은 %d입니다.\n", sum);

    printf("\n---2번 문제---\n");
    char **str = NULL;
    printf("문자열의 개수: ");
    scanf("%d", &size);
    str = malloc(sizeof(char *)*size);
    for(int i=0;i<size;i++){
        getchar();
        str[i] = (char *)malloc(100);
        scanf("%[^\n]s",str[i]);
    }
    printf("[ ");
    for(int i=0;i<size;i++){
        printf("\"%s\" ", str[i]);
    }
    printf(" ]\n");

    printf("\n---3번 문제---\n");
    printf("주소의 개수: ");
    scanf("%d", &size);
    struct address* contact = (struct address*)malloc(size*sizeof(struct address));
    for(int i=0;i<size;i++){
        getchar();
        char name[80]={0}, number[80]={0};
        printf("이름을 입력하시오: ");
        scanf("%[^\n]s", name);
        getchar();
        strcpy(contact[i].name, name);
        printf("휴대폰 번호를 입력하시오: ");
        scanf("%[^\n]s", number);
        strcpy(contact[i].number, number);
    }
    printf("==============================\n");
    printf("이름\t\t휴대폰 번호\n");
    printf("==============================\n");
    for(int i=0;i<size;i++)
        printf("%s\t%s\n", contact[i].name, contact[i].number);
    printf("==============================\n");
    printf("\n---4번 문제---\n");
    char* a = get_word();
    printf("동적 메모리에 저장된 단어는 %s입니다.", a);
}

char* get_word(){
    char *s = (char *)malloc(50);
    if(s == NULL){
        printf("메모리 할당 오류\n");
        exit(1);
    }
    printf("단어를 입력하시오(최대 50글자):");
    scanf("%s", s);
    return s;
}