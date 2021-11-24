#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void str_upper(char *s);
int get_response(char *prompt);
int str_chr(char *s, int c);

int main(){

    printf("---1번 문제---\n");
    printf("문자를 빙력하시오: ");
    char a = _getch();
    _putch(a);
    printf("\n아스키 코드값=%d", a);
    
    printf("\n\n---2번 문제---\n");
    char text[100];
    printf("공백 문자가 있는 문자열을 입력하시오: ");
    scanf("%[^\n]s", text);
    for(int i=0;text[i]!='\0';i++){
        if(isspace(text[i]))
            continue;
        printf("%c", text[i]);
    }
    getchar();

    printf("\n\n---3번 문제---\n");
    char text2[100]={'\0'};
    int check;
    printf("문자열을 입력하시오: ");
    scanf(" %[^\n]s", text2);
    printf("개수를 셀 문자를 입력하시오: ");
    scanf(" %c", &check);
    printf("%c의 개수: %d", check, str_chr(text2, check));
    getchar();

    printf("\n\n---4번 문제---\n");
    int alphabets[26] = {0};
    char text3[100];
    printf("문자열을 입력하시오: ");
    scanf(" %[^\n]s", text3);
    for(int i=0; text3[i]!='\0';i++){
        text3[i]+=isupper(text3[i])?'a'-'A':0;
        alphabets[text3[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        printf("%c: %d\n", 'a'+i, alphabets[i]);
    }
    getchar();

    printf("\n---5번 문제---\n");
    while(1){
        printf("\n문자를 입력하시오: ");
        a = getchar();
        if(a=='.')break;
        if(isalpha(a)){
            a+=isupper(a)?'a'-'A':'A'-'a';
            putchar(a);
            getchar();
            continue;
        }
        printf("%s", "알파벳을 입력하여 주세요");
        getchar();
    }
    getchar();

    printf("\n---6번 문제---\n");
    char strings[100];
    printf("문자열을 입력하시오: ");
    scanf("%[^\n]s", strings);
    str_upper(strings);
    getchar();
    
    printf("\n\n---7번 문제---\n");
    char prompt[3] = {'\0'};
    int g;
    printf("게임을 하시겠습니까(yes/ok/no): ");
    scanf("%s", prompt);
    g = get_response(prompt);
    if(g){
        if(g==3)
            printf("부정적인 답변");
        else
            printf("긍정적인 답변");
    }
    else{
        printf("알 수 없는 답변");
    }
    getchar();

    printf("\n\n---8번 문제---\n");
    char s[100], seps[] = " ,.\t\n";
    int count = 0;
    printf("문자열을 입력하시오: ");
    scanf("%[^\n]s", s);
    if(strtok(s, seps)!=NULL){
        count++;
    }
    for(;strtok(NULL, seps)!=NULL;count++);
    printf("단어의 수는 %d입니다.", count);
    getchar();

    printf("\n\n---9번 문제---\n");
    char str[100]={'\0'};
    printf("텍스트를 입력하시오: ");
    scanf("%[^\n]s", str);
    int length = strlen(str);
    if(islower(str[0]))str[0]+='A'-'a';
    if(str[length-1]!='.')str[length]='.';
    printf("수정된 텍스트: %s", str);

    printf("\n\n---10번 문제---\n");
    printf("문자열을 입력하시오: ");
    char texts[80];
    scanf("%s", texts);
    int tf=1;
    length = strlen(texts);
    for(int i=0, j=length-1;i<j;i++, j--){
        if(tolower(texts[i])!=tolower(texts[j])){
            tf=0;
            break;
        }
    }
    if(tf)    printf("회문입니다.\n");
    else      printf("회문이 아닙니다.\n");
    getchar();

    printf("\n\n---11번 문제---\n");
    printf("문자열을 입력하시오: ");
    char txt[80] = { 0 };
    int txt2[80] = { 0 };
    char seps2[] = " ";
    count = 0;
    scanf("%[^\n]s", txt);
    txt2[0] = strtok(txt, seps2);
    for (count = 0; *(txt2+count) != NULL;) {
        *(txt2 + ++count) = strtok(NULL, seps2);
    }
    if (txt2[0] == NULL) printf("\n");
    for (int i = count - 1; i >= 0; i--) {
        printf("%s", txt2[i]);
        if (i == 0) printf("\n");
        else printf(" ");
    }
    getchar();

    printf("\n\n---12번 문제---\n");
    printf("성과 이름을 대문자로 입력하시오 (예: HONG GILDONG): ");
    char full_name[80] = {0};
    int nth_name[2] = {0};
    scanf("%[^\n]s", full_name);
    for(int i=0;i<strlen(full_name);i++)
        full_name[i] = tolower(full_name[i]);
    
    nth_name[1] = strtok(full_name, seps2);
    nth_name[0] = strtok(NULL, seps2);
    strtok(NULL, seps2);
    printf("%s, %s", nth_name[0], nth_name[1]);

    getchar();
    
    printf("\n\n---13번 문제---\n");
    printf("문자열을 입력하시오: ");
    char seps3[]=".,", count_dots[80]={0};
    scanf("%[^\n]s", count_dots);
    count = 0;
    strtok(count_dots, seps3);
    for(;strtok(NULL, seps3)!=NULL;count++);
    printf("구두점의 개수는 %d입니다.\n", count);
    getchar();

    printf("\n\n---14번 문제---\n");
    char original[80], find[80], change[80];
    printf("문자열을 입력하시오: ");
    scanf("%[^\n]s", original);
    getchar();
    printf("찾을 문자열: ");
    scanf("%[^\n]s", find);
    getchar();
    printf("바꿀 문자열: ");
    scanf("%[^\n]s", change);
    length = strlen(original), tf=0;
    int length2 = strlen(find);
    for(count=0;count<length;count++){
        if(tf==length2){
            break;
        }
        if(*(find+tf)==*(original+count))
            tf++;
        else tf=0;
    }
    if(tf<length2) printf("%s\n", original);
    else{
        count -= length2;
        for(int i=0;i<tf;i++){
            if(*(change+i)==0) *(change+i)=*(original+(count+i));
            *(original+(count+i))=*(change+i);
        }
        printf("%s\n", original);
    }

    getchar();

    printf("\n\n---15번 문제---\n");
    printf("연산을 입력하시오 (ex: add 3 5)\n(더하기: add, 배기: sub, 곱하기: mul, 나누기: div)\n");
    char operator[4]={ 0 }, operator_list[4][4] = { "add", "sub", "mul", "div" };
    int num[2]={0};
    scanf("%c%c%c %d %d", &operator[0], &operator[1], &operator[2], &num[0], &num[1]);
    printf("연산의 결과: ");
    for (int i = 0; i < 4; i++) {
        if (strcmp(operator, operator_list[i]) == 0) {
            switch (i) {
            case 0: printf("%d", num[0] + num[1]);
                break;
            case 1: printf("%d", num[0] - num[1]);
                break;
            case 2: printf("%d", num[0] * num[1]);
                break;
            case 3: printf("%lf", 1.0 * num[0] / num[1]);
                break;
            }
        }
    }

    printf("\n\n---16번 문제---\n");
    char advertise_ment[80] = { 0 };
    count=0;
    printf("광고하고 싶은 텍스트를 입력하시오: ");
    scanf("%[^\n]s", advertise_ment);
    length = strlen(advertise_ment);
    for (int i = 0; i < length + 5; i++) {
        printf("=");
    }
    printf("\n");
    getchar();
    --length;
    while (1) {
        if(count<=length)
            printf("%s   ", (advertise_ment + count));
        else 
            for (int i = 0; i <= (length + 3)-count; i++) printf(" ");

        for (int i = 0; i < count; i++)
            printf("%c", *(advertise_ment + i));
        getchar();
        count++;
        if (count > length+3) count = 0;
    }

}

void str_upper(char *s){
    for(int i=0;s[i]!='\0';i++){
        if(isalpha(s[i]))
            s[i]-=isupper(s[i])?0:'a'-'A';
        printf("%c", s[i]);
    }
}

int get_response(char *prompt){
    char pn[3][3] = {
        "yes", "ok\0", "no\0"
    };
    for(int i=0;i<3;i++){
        if(!strncmp(pn[i], prompt, 3)){
            return i+1;
        }
    }
    return 0;
}

int str_chr(char *s, int c){
    int count=0;
    for(int i=0;s[i]!='\0';i++)
        if(s[i]==(char)c)
            count++;
    return count;
}