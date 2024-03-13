#include <stdio.h>
int main(){
    int a;

    for(scanf("%d", &a);a>0;a/=10){
        if ((a%10)==((a/10)%10)){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
