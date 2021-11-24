#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <conio.h>

int array_equal(int a[], int b[], int size);
void array_copy(int a[], int b[], int size);
void vector_add(double x[], double y[], double z[]);
double vector_dot_prod(double x[], double y[]);
void scalar_mult(int a[][3], int scalar);
void transpose(int a[][3], int b[][3]);
void zero(char a[][10], char b[][10]);

int main(){
    srand((unsigned)time(NULL));/*
    printf("---1번 문제---\n");
    int days[]={31,29,31,30,31,30,31,31,30,31,30,31}; // 변수 정의
    for(int i=0;i<12;i++)
        printf("%d월은 %d일까지 있습니다.\n", i+1, days[i]); // 출력

    printf("\n---2번 문제---\n");
    int x[10], max=-2147483648, min=2147483647; // int형의 최소값과 최대값
    for(int i=0;i<10;i++){
        x[i] = rand();
        if(x[i]>max) max=x[i];
        if(x[i]<min) min=x[i];
    }
    printf("최대값은 %d\n최소값은 %d\n", max, min);

    printf("\n---3번 문제---\n");
    int a[10] = {1,2,3,0,0,0,0,0,0,0}, b[10]={0,0,0,0,0,0,0,0,0,0};
    for(int i=0;i<10;i++)  printf("%d ", a[i]);
    
    printf("\n");
    for(int i=0;i<10;i++)  printf("%d ", b[i]);

    printf("\n2개의 배열은 %s", array_equal(a, b, 10)?"같음":"다름");
    
    printf("\n---4번 문제---\n");
    array_copy(a, b, 10);

    printf("\n---5번 문제---\n");
    // int a[10];
    max=0;
    for(int i=0;i<10;i++)
        a[i]=0; //리스트 선언
    for(int i=0;i<100;i++)
        a[rand()%10]++;
    for(int i=0;i<10;i++)
        max=max<a[i]?a[i]:max;
    printf("가장 많이 나온수=%d\n", max);

    printf("\n---6번 문제---\n");
    int list[3][5] = { {12,56,32,16,98},
    {99,56,34,41,3},
    {65,3,87,78,21}}, sum;
    for(int i=0;i<3;i++){
        sum=0;
        for(int j=0;j<5;j++)
            sum+=list[i][j];
        printf("%d행의 합계: %d\n", i, sum);
    }
    for(int i=0;i<5;i++){
        sum=0;
        for(int j=0;j<3;j++)
            sum+=list[j][i];
        printf("%d열의 합계: %d\n", i, sum);
    }
    printf("\n---7번 문제---\n");
    int squares[10][3], number;
    for(int i=1;i<=10;i++)
        squares[i-1][0]=i, squares[i-1][1]=i*i, squares[i-1][2]=i*i*i;
    printf("정수를 입력하시오: ");
    scanf("%d", &number);
    for(int i=0;i<10;i++){
        if(squares[i][2]==number)
            printf("%d의 세제곱근은 %d\n", number, squares[i][0]);
        if(squares[i][1]==number) 
            printf("%d의 제곱근은 %d\n", number, squares[i][0]);
        if(squares[i][0]==number)
            printf("%d의 제곱은 %d\n%d의 세제곱은 %d\n", number, squares[i][1], number, squares[i][2]);
    }

    printf("\n---8번 문제---\n");
    int data[10];
    double avg;
    sum=0;
    for(int i=0;i<10;i++){
        printf("데이터를 입력하시오: ");
        scanf("%d", &data[i]);
        sum+=data[i];
    }
    avg=sum/10.0;
    double v_sum=0;
    for(int i=0;i<10;i++)
        v_sum+=pow((data[i]-avg), 2);
    printf("평균값은 %g\n표준편차값은 %lf\n", avg, sqrt(v_sum/10.0));
    
    printf("\n---9번 문제---\n");
    int scores[5][3]/*, min, max;
    for(int i=0;i<5;i++)
        for(int j=0;j<3;j++)
            scores[i][j]=rand()%101;
    for(int i=0;i<3;i++){
        min=100, max=0;
        for(int j=0;j<5;j++){
            if(min>scores[j][i])
                min=scores[j][i];
            if(max<scores[j][i])
                max=scores[j][i];
        }
        printf("시험 #%d의 최대점수=%d\n시험#%d의 최저점수=%d\n", i+1, max, i+1, min);
    }

    printf("\n---10번 문제---\n");
    double vector_x[3] = {1.0, 2.0, 3.0}, vector_y[3] = {1.0, 2.0, 3.0}, vector_sum[3];
    vector_add(vector_x, vector_y, vector_sum);
    printf("벡터의 합 = [ ");
    for(int i=0;i<3;i++)
        printf("%lf ", vector_sum[i]);
    printf("]\n벡터의 내적 = %lf\n", vector_dot_prod(vector_x, vector_y));

    printf("\n---11번 문제---\n");
    int product[10] = {3, 5, 2, 4, 1, 4, 2, 3, 5, 1};
    printf("상품 번호를 입력하시요: ");
    scanf("%d", &number);
    printf("상품 번호 %d의 위치는 %d입니다.\n", number, product[number]);

    printf("\n---12번 문제---\n");
    int matrix[3][3], matrix2[3][3];
    number=1;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            matrix[i][j]=number++;
    transpose(matrix, matrix2);
    scalar_mult(matrix, 2);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            printf("%2d ", matrix[i][j]);
        printf("\n");
    }
    printf("-----------\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            printf("%d ", matrix2[i][j]);
        printf("\n");
    }

    printf("\n---13번 문제---\n");
    int binary[32], n, i;
    printf("2진수로 변환할 10진수 정수를 적어주세요: ");
    scanf("%d", &n);
    printf("%d->", n);
    for(i = 0; i < 32 && n > 0; i++){
        binary[i] = n%2;
        n = n / 2;
    }
    for(i-=1;i>=0;i--)
        printf("%d", binary[i]);
*/
    printf("\n\n---14번 문제---\n");
    int row, col, m[2], n[2];
    printf("줄/칸을 입력하세요: ");
    scanf("%d %d", &row, &col);
    char tile[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%c ", tile[i][j]='.');
        }
        printf("\n");
    }
    m[0]=row/2, n[0]=col/2;
    while(1){
        m[1]=m[0], n[1]=n[0];
        int j=rand()%8;
        switch(j){
            case 0:
                m[0]++;
                break;
            case 1:
                m[0]--;
                break;
            case 2:
                n[0]++;
                break;
            case 3:
                n[0]--;
                break;
            case 4:
                m[0]++, n[0]--;
                break;
            case 5:
                m[0]++, n[0]++;
                break;
            case 6:
                m[0]--, n[0]--;
                break;
            default:
                m[0]--, n[0]++;
                break;
        }
        if(m[0]>=row)m[0]--;
        if(m[0]<0)m[0]++;
        if(n[0]>=col)n[0]--;
        if(n[0]<0)n[0]++;
        if(tile[m[0]][n[0]]=='*'){
            m[0]=m[1], n[0]=n[1];
            continue;
        }
        tile[m[0]][n[0]]='*';
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++)
                printf("%c ", tile[i][j]);
            printf("\n");
        }
        getchar();
        system("cls");
    }
    /*printf("\n");
    printf("\n---15번 문제---\n");
    char minesweeper[10][10], board[10][10];
    int count_b=0, count_o=0, flag=0, correct_flag=0;
    //폭탄 위치 설정, 보드판 초기화
    for(i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(rand()%10<2) minesweeper[i][j]='#';
            board[i][j]='.';
        }
    }

    for(i=0;i<10;i++){
        for(int j=0;j<10;j++){
            count=0;
            //주변 폭탄 개수 세기
            if(minesweeper[i][j]!='#'){
                for(int k=-1;k<=1;k++){
                    for(int h=-1;h<=1;h++){
                        n=i+k;m=j+h;
                        //예외 설정
                        if(n>=10) continue;
                        else if(n<0) continue;
                        if(m>=10) continue;
                        else if(m<0) continue;
                        if(k==0&&h==0) continue;
                        if(minesweeper[n][m]=='#') count++;
                    }
                }
                minesweeper[i][j]=(char)(count+48);
            }
            //총 폭탄 개수 세기
            else count_b++;
        }
    }
    while(1){
        system("cls");
        printf("남은 깃발 개수: %d\n", count_b-flag);
        printf("1 2 3 4 5 6 7 8 9 10\n--------------------\n");
        for(i=0;i<10;i++){
            for(int j=0;j<10;j++)
                printf("%c ", board[i][j]);
            printf("| %d\n", i+1);
        }
        printf("열어볼 좌표값을 입력하세요(X Y)\n(X좌표에 10을 더해서 입력하면 깃발)\n: ");
        scanf("%d %d", &m, &n);
        printf("\n");
        if(n<1||n>10||m<1||m>20){
            printf("잘못된 값을 입력하였습니다. 다시 입력해주세요(1 이상 10 이하의 자연수)\n");
            continue;
        }
        n--, m--;
        if(0<=m&&m<10){
            if(board[n][m]=='V'){
                printf("깃발이 꽂혀있습니다. 다른 칸을 선택해주세요\n");
                continue;
            }
            if(board[n][m]!='.'){
                printf("이미 열은 칸입니다. 다시 선택해주세요\n");
                continue;
            }
            board[n][m]=minesweeper[n][m];
            count_o++;
            if(minesweeper[n][m]=='#'){
                printf("폭탄을 터트리셨습니다.\n");
                for(i=0;i<10;i++)
                    for(int j=0;j<10;j++)
                        if(board[i][j]=='.' && minesweeper[i][j]=='#')
                            board[i][j]=minesweeper[i][j];
                        else if(board[i][j]=='V' && minesweeper[i][j]=='#')
                            board[i][j]='*';
                break;
            }
            else if(minesweeper[n][m]=='0'){
                for(i=n;i>=0;i--){
                    if(minesweeper[i][m]=='0')
                        for(int xx=-1;xx<=1;xx++){
                            int ii=i-xx;
                            if(ii<0) continue;
                            if(ii>9) continue;
                            for(int y=-1;y<=1;y++){
                                int jj=m-y;
                                if(jj<0) continue;
                                if(jj>9) continue;
                                if(minesweeper[ii][jj]=='0')
                                    board[ii][jj]='0';
                                else board[ii][jj] = minesweeper[ii][jj];
                            }
                        }
                    else{
                        board[i][m] = minesweeper[i][m];
                        break;
                    }
                }
                for(i=n;i<10;i++){
                    if(minesweeper[i][m]=='0')
                        for(int xx=-1;xx<=1;xx++){
                            int ii=i-xx;
                            if(ii<0) continue;
                            if(ii>9) continue;
                            for(int y=-1;y<=1;y++){
                                int jj=m-y;
                                if(jj<0) continue;
                                if(jj>9) continue;
                                if(minesweeper[ii][jj]=='0')
                                    board[ii][jj]='0';
                                else board[ii][jj] = minesweeper[ii][jj];
                            }
                        }
                    else{
                        board[i][m] = minesweeper[i][m];
                        break;
                    }
                }
                for(i=m;i<10;i++){
                    if(minesweeper[n][i]=='0')
                        for(int xx=-1;xx<=1;xx++){
                            int ii=n-xx;
                            if(ii<0) continue;
                            if(ii>9) continue;
                            for(int y=-1;y<=1;y++){
                                int jj=i-y;
                                if(jj<0) continue;
                                if(jj>9) continue;
                                if(minesweeper[ii][jj]=='0')
                                    board[ii][jj]='0';
                                else board[ii][jj] = minesweeper[ii][jj];
                            }
                        }
                    else{
                        board[n][i] = minesweeper[n][i];
                        break;
                    }
                }
                for(i=m;i>=0;i--){
                    if(minesweeper[n][i]=='0')
                        for(int xx=-1;xx<=1;xx++){
                            int ii=n-xx;
                            if(ii<0) continue;
                            if(ii>9) continue;
                            for(int y=-1;y<=1;y++){
                                int jj=i-y;
                                if(jj<0) continue;
                                if(jj>9) continue;
                                if(minesweeper[ii][jj]=='0')
                                    board[ii][jj]='0';
                                else board[ii][jj] = minesweeper[ii][jj];
                            }
                        }
                    else{
                        board[n][i] = minesweeper[n][i];
                        break;
                    }
                }
                
            }
            else
                board[n][m]=minesweeper[n][m];
        }
        else if(10<=m&&m<20){
            m-=10;
            if(board[n][m]=='V'){
                board[n][m]='.';
                if(minesweeper[n][m]=='#') correct_flag--;
                flag--;
                continue;
            }
            else if(count_b-flag==0){
                printf("깃발이 부족합니다.");
                continue;
            }
            else if(board[n][m]!='.'){
                printf("이미 열은 칸입니다. 다시 선택해주세요\n");
                continue;
            }
            else {
                board[n][m]='V';
                flag++;
                if(minesweeper[n][m]=='#') correct_flag++;
            }
            
        }
        if(100-count_o==count_b&&correct_flag==count_b){
            printf("축하합니다. 모든 칸을 다 열었습니다.\n");
            break;
        }
    }
    for(i=0;i<10;i++){
        for(int j=0;j<10;j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }

    printf("\n---16번 문제---\n");
    char game[10][10], input;
    int now_x=0, now_y=0, monster_1x=4, monster_2x=6, monster_1y=3, monster_2y=5;
    for(i=0;i<10;i++)
        for(int j=0;j<10;j++)
            game[i][j]='.';
    while(1){
        game[9][9]='G';
        game[monster_1y][monster_1x]='M', game[monster_2y][monster_2x]='M', game[now_y][now_x]='#';
        for(i=0;i<10;i++){
            for(int j=0;j<10;j++)
                printf("%c ", game[i][j]);
            printf("\n");
        }
        game[monster_1y][monster_1x]='.', game[monster_2y][monster_2x]='.', game[now_y][now_x]='.';
        input = _getch();
        switch(rand()%8){
            case 0:
                monster_1x++;
                break;
            case 1:
                monster_1x--;
                break;
            case 2:
                monster_1y++;
                break;
            case 3:
                monster_1y--;
                break;
            case 4:
                monster_1x++, monster_1y++;
                break;
            case 5:
                monster_1x++, monster_1y--;
                break;
            case 6:
                monster_1x--, monster_1y++;
                break;
            default:
                monster_1x--, monster_1y--;
                break;
        }
        switch(rand()%8){
            case 0:
                monster_2x++;
                break;
            case 1:
                monster_2x--;
                break;
            case 2:
                monster_2y++;
                break;
            case 3:
                monster_2y--;
                break;
            case 4:
                monster_2x++, monster_2y++;
                break;
            case 5:
                monster_2x++, monster_2y--;
                break;
            case 6:
                monster_2x--, monster_2y++;
                break;
            default:
                monster_2x--, monster_2y--;
                break;
        }
        monster_2y%=10, monster_1y%=10, monster_2x%=10, monster_1x%=10;
        if(monster_2y<0) monster_2y=9; if(monster_1y<0) monster_1y=9; if(monster_2x<0) monster_2x=9; if(monster_1x<0) monster_1x=9;
        if(monster_1x==monster_2x&&monster_1y==monster_2y) monster_1x--;
        if(monster_1x<0) monster_1x=9;
        if((monster_1x==now_x&&monster_1y==now_y)||(monster_2x==now_x&&monster_2y==now_y)){
            printf("몬스터에게 닿아서 죽었습니다.");
            break;
        }
        switch(input){
            case 'w':
                now_y--;
                break;
            case 'a':
                now_x--;
                break;
            case 's':
                now_y++;
                break;
            case 'd':
                now_x++;
                break;
        }
        now_y=now_y>=10?9:now_y, now_y=now_y<0?0:now_y, now_x=now_x>=10?9:now_x, now_x=now_x<0?0:now_x;
        if((monster_1x==now_x&&monster_1y==now_y)||(monster_2x==now_x&&monster_2y==now_y)){
            printf("몬스터에게 닿아서 죽었습니다.");
            break;
        }
        else if(now_x==9&&now_y==9){
            printf("축하합니다! 코인을 획득하였습니다!");
            break;
        }
        system("cls");
    }*/
    return 0;
}


int array_equal(int a[], int b[], int size){
    for(int i=0;i<size;i++)
        if(a[i]!=b[i]) return 0;
    return 1;
}

void array_copy(int a[], int b[], int size){
    for(int i=0;i<size;i++){
        b[i]=a[i];
        printf("%d ", a[i]);
    }
    printf("\n");
    for(int i=0;i<size;i++)
        printf("%d ", b[i]);
    printf("\n");
}

void vector_add(double x[], double y[], double z[]){
    for(int i=0;i<3;i++)
        z[i]=x[i]+y[i];
}

double vector_dot_prod(double x[], double y[]){
    double vdp=0;
    for(int i=0;i<3;i++)
        vdp+=x[i]*y[i];
    return vdp;
}

void scalar_mult(int a[][3], int scalar){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            a[i][j]*=scalar;
}
void transpose(int a[][3], int b[][3]){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            b[j][i]=a[i][j];
}

void zero(char a[][10], char b[][10]);