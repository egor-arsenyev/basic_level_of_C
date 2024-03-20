#include <stdio.h>

int middle(unsigned int a, unsigned int b){
    return (a+b)>>1;
}

int main(){
    unsigned int num1, num2;

    scanf ("%d%d", &num1, &num2);
    printf("%d\n", middle(num1, num2));
    return 0;
}
