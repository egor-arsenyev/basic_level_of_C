#include <stdio.h>

int main(){
    int a;
    int rev_a = 0;

    for(scanf("%d", &a);a>0;a/=10){
        rev_a = rev_a*10 + (a%10);
    }
    printf("%d\n", rev_a);
    return 0;
}
