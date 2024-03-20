#include <stdio.h>

int grow_up(int n){
    for ( ; n > 0; n/=10){
        if ((n%10)<=((n/10)%10))
            return 0;
    }
    return 1;
}
int main(void){
    int x;

    scanf("%d", &x);
    if (grow_up(x))
        printf ("YES\n");
    else
        printf ("NO\n");
    return 0;
}
