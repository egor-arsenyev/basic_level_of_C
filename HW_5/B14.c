#include <stdio.h>

int main(void){
    unsigned int a, count = 0;
    do{
        scanf("%d", &a);
        count++;
    } while (a !=0);
    printf("%d", count - 1);
    return 0;
}
