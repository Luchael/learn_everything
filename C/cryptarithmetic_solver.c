#include <stdio.h>
int main(){
    for(int h=0;h<10;h++){
        for(int e=0;e<10;e++){
            if(e==h) continue;
            for(int l=0;l<10;l++){
                if(l==e||l==h) continue;
                for(int m=0;m<10;m++){
                    if(m==e||m==l||m==h) continue;
                    for(int o=0;o<10;o++){
                        if(o==m||o==e||o==l||o==h) continue;
                        for(int d=0;d<10;d++){
                            if(d==o||d==m||d==e||d==l||d==h) continue;
                            for(int s=0;s<10;s++){
                                if(s==d||s==o||s==m||s==e||s==l||s==h) continue;
                                if(1000*d+100*l+10*e+h+1000*d+100*l+10*o+m==10000*s+1000*m+100*o+10*o+d)
                                    printf("y: %d, a: %d, l: %d\np: %d, w: %d, o: %d\ns: %d\n----------------\n", h, e, l, d, m, o, s);
                            }
                        }
                    }
                }
            }
        }
    }
}