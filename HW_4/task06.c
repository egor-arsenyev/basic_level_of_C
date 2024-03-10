#include <stdio.h>

int main(void){
    int first, second;
    printf("input two numbers:\n");

    scanf("%d%d",&first,&second);
    if (first > second)
        printf("Above");
    else if(first < second)
        printf("Less");
    else
        printf("Equal");

    return 0;
}
