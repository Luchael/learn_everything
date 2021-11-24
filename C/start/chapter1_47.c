#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    double radius;
    printf("21번 문제\n원의 반지름을 입력해주세요: ");
    scanf("%lf", &radius);
    printf("원의 지름은 %lf 입니다.\n원의 둘레는 %lf입니다.\n", radius*2, radius*2*3.14);

    double a, b, c;
    printf("22번 문제\n정수 3개를 입력해주세요: ");
    scanf("%lf%lf%lf", &a, &b, &c);
    printf("세 수중에 가장 큰 수는 %lf입니다.\n",a>b?(a>c?a:c):(b>c?b:c));

    char cup1[6] = "juice\0", cup2[6] = "milk\0", cup3[6]="\0";
    printf("23번 문제\ncup1에 담겨있는 것: %s, cup2에 담겨있는 것: %s\n", cup1, cup2);
    strcpy(cup3, cup1), strcpy(cup1, cup2), strcpy(cup2, cup3);
    printf("cup1에 담겨있는 것: %s, cup2에 담겨있는 것: %s\n", cup1, cup2);

    int sorted[1000], arr[1000], fill, tmp, h, findings, q, updown, temp, fill2;
    //랜덤 배열 만들기
    for(fill = 0; fill<1000; fill++){
        arr[fill] = rand()%100000;
    }

    /*//랜덤 배열 출력
    printf("------------------------\n정렬 안 된거\n------------------------\n");
    for(fill = 0; fill < 1000; fill++){
        printf("%d번째: %d\t", fill+1, arr[fill]);
    }*/
    temp=100000;
    //숫자 입력받고, 랜덤한 배열에서 찾기
    printf("100000미만의 자연수를 입력하세요: ");
    scanf("%d", &findings);
    if(findings<0 || findings>=100000) return 0;
    for(fill = 0 ; fill<1000; fill++){
        if(findings == arr[fill]) {
            printf("랜덤한 배열에서 %d는 %d번째에 있습니다!\n", findings, fill+1);
            break;
        }
        else{
            tmp = (findings-arr[fill]);
            tmp = tmp<0? (~tmp):tmp;
            if(temp > tmp){
                temp=tmp;
                fill2=fill;
            }
        }
        if(fill==999){
            printf("%d와 가장 가까운 수는 %d만큼 차이나는 %d번째 수인 %d입니다.\n", findings, temp, fill2+1, arr[fill2]);
        }
    }

    printf("100000미만의 자연수를 다시 입력하세요: ");
    scanf("%d", &findings);
    //배열 대입
    for(fill=0;fill<1000;fill++) {
        sorted[fill] = arr[fill];
    }

    //!선택정렬
    for(fill=0;fill<1000;fill++){
        tmp=sorted[fill];
        for(h=fill-1; h>=0; h--){
            if(tmp < sorted[h]) sorted[h+1]=sorted[h];
            else break;
        }
        sorted[h+1]=tmp;
    }
    /*
    //정렬된 배열 출력
    printf("------------------------\n정렬 된거\n------------------------\n");
    for(fill=0;fill<1000;fill++) {
        printf("%d번째: %d\t", fill+1, sorted[fill]);
    }*/
    
    //정렬된 배열에서 숫자 찾기
    //*아니 솔직히 걍 for 문 쓰는게 훨씬 이득일듯;; 너무 복잡해;;
    h=2, fill=1;
    while(1){
        q=(fill*1000/h);
        tmp = sorted[q];
        if(tmp == findings){
            printf("정렬된 배열에서 %d는 %d번째에 있습니다!\n", findings, q+1);
            break;
        }
        h=h*2;
        if(tmp < findings){
            fill = fill*2+1;
            updown=1;
        }
        else{
            fill = fill*2-1;
            updown=0;
        }
        if(h>=2048){
            updown = updown==0?q:(q+2);
            printf("정렬된 배열에서 %d는\n%d번째 숫자인 %d와 %d번째 숫자인%d사이에 있습니다!\n", findings, q+1, sorted[q], updown, sorted[updown+1]);
            break;
        }
    }


    int i, j, index, max;
    printf("25번 문제\n얼마 이하의 정수를 구할건지 적어주십시오 (최댓값: 20만): ");
    scanf("%d", &max);
    if(max==2)printf("2");
    else if(max>200000&&0<max)printf("범위에 맞는 수를 입력하여주세요.");
    else{
        int prime[200000];
        prime[0] = 2;
        prime[1] = 3;
        index = 2;
        for(i = 4; i <= max; i ++){
            for(j = 2; j <= i; j++){
                if(i==j) prime[index]=i, index++;
                if(i%j==0) break;
            }
        }
        printf("%d 이하의 소수 목록입니다.\n", max);
        for(i = 0; i < sizeof(prime)/sizeof(prime[0]); i ++){
            if(prime[i] == 0) return 0;
            printf("%d", prime[i]);
            if(i % 32 == 31) printf("\n");
            else printf("\t");
        }
    }
}