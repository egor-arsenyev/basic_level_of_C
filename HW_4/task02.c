#include <stdio.h>

int main(void){
    int a, b, c, max;

    printf("input three numbers:\n");
    scanf("%d%d%d", &a, &b, &c);

    if ((a > b) && (a > c))
        max = a;
    else if ((b > a) && (b > c))
        max = b;
    else
        max = c;

    printf ("%d\n", max);

    return 0;
}
