#include <stdio.h>

int is2pow(int n){
    if (n == 2)
        return 1;

    if ((n%2)||(n==0))
        return 0;
    else
     return is2pow(n/2);
}

int main(){
    int num;

    scanf("%d", &num);

    if (is2pow(num))
        printf ("YES\n");
    else
        printf ("NO\n");

    return 0;
}
