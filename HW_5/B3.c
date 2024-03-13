#include <stdio.h>

#define BYTE 8

unsigned int abs (int val){
    unsigned int absVal;
    int const mask = val >> sizeof(int)*BYTE - 1;
    absVal = (val + mask) ^ mask;
    return absVal;
}

int main(){
    int a, b, sum;

    scanf ("%d %d", &a, &b);
    if (a>b){
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
    if ((abs(a)<100)&&(abs(b)<100)){
        for (int i=a;i<=b;i++){
            sum+=(i*i);
        }
    printf ("%d ",  sum);
    }
    return 0;
}
