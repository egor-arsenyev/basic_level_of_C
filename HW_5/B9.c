#include <stdio.h>

int main(){
    int a;

    for(scanf("%d", &a);a>0;a/=10){
        if (a%2){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
