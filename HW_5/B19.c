#include <stdio.h>

int main(){
    int a, sum;

    for(scanf("%d", &a);a>0;a/=10){
        sum += a%10;
    }
    if (sum == 10)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
