#include <stdio.h>

int main(void){
    int a, b, first, second;

    printf("input two numbers:\n");
    scanf ("%d%d", &a, &b);

    if (a<b){
        first = a;
        second = b;
    }
    else{
        first = b;
        second = a;
    }
    printf ("%d %d\n", first, second);

    return 0;
}
