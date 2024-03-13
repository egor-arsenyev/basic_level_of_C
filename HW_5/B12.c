#include <stdio.h>

int main(){
    int a, rem;
    int min = 9;
    int max = 0;

    for(scanf("%d", &a);a>0;a/=10){
        rem = a%10;
        if (rem < min) min = rem;
        if (rem > max) max = rem;
    }
    printf("%d %d\n", min, max);
    return 0;
}
