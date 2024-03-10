#include <stdio.h>

int main(void){
    int a, b, c;

    printf("input three numbers:\n");
    scanf("%d%d%d", &a, &b, &c);

    if (a < b && b < c)
        printf ("YES");
    else
        printf ("NO");

    return 0;
}
