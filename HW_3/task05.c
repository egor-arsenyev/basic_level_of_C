#include <stdio.h>

int main(void){
    int a, ones, tens, hundreds;

    printf("input a 3-digit number:\n");
    scanf ("%d", &a);

    hundreds = a/100;
    a %= 100;
    tens = a/10;
    a %= 10;
    ones = a;

    printf ("%d\n", ones * tens * hundreds);

    return 0;
}
