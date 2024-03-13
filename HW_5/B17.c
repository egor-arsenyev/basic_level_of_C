#include <stdio.h>

int main(void){
    unsigned int a, num;

    scanf("%d", &a);

    for(int i = 10; i<=a; i++){
        unsigned int sum = 0;
        unsigned int mul = 1;

        for(num = i; num>0; num/=10){
            sum += (num%10);
            mul *= (num%10);
        }
        if (sum == mul)
            printf("%d ", i);
    }

    return 0;
}
