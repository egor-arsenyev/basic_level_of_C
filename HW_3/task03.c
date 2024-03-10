#include <stdio.h>

int main(void){
    int a, b, sub;

    printf("input two numbers:\n");
    scanf ("%d%d", &a, &b);
    sub = a - b;
    printf ("%d - %d = %d\n", a, b, sub);

    return 0;
}
