#include <stdio.h>

int main(){
    int a;
    int even = 0;
    int odd  = 0;

    for(scanf("%d", &a);a>0;a/=10){
        if (a%2)
            odd++;
        else
            even++;
    }
    printf("%d %d\n", even, odd);
    return 0;
}
