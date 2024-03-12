#include <stdio.h>

int main(void){
    unsigned int a, b, c;

    printf("enter the side lengths of triangle:\n");
    scanf("%d %d %d", &a, &b, &c);
    if (((a+b)>c)&&((a+c)>b)&&((b+c)>a))
        printf ("triangle exists\n");
    else
        printf ("triangle does not exist\n");
    return 0;
}
