#include <stdio.h>

int main(void){
    int a, b, c;
    float average;

    printf("input three numbers:\n");
    scanf ("%d%d%d", &a, &b, &c);
    average = ((float)(a + b + c))/3;//typecasting to float
    printf ("%.2f\n", average);

    return 0;
}
