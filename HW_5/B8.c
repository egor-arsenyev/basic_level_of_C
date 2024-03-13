#include <stdio.h>
int main(){
    int a;
    int nines = 0;

    for(scanf("%d", &a);a>0;a/=10){
        if ((a%10)==9)
            nines++;
    }
    if (nines == 1)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
