#include <stdio.h>

int main(void){
    int a, ones, tens, hundreds, max;

    printf("input a 3-digit number:\n");
    scanf ("%d", &a);

    hundreds = a/100;
    a %= 100;
    tens = a/10;
    a %= 10;
    ones = a;

   if ((hundreds > tens) && (hundreds > ones))
        max = hundreds;
    else if ((tens > hundreds) && (tens > ones))
        max = tens;
    else
        max = ones;

    printf ("%d\n", max);

    return 0;
}
