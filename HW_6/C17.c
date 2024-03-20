#include <stdio.h>

int is_happy_number(int n){
        unsigned int num = 0;
        unsigned int sum = 0;
        unsigned int mul = 1;

        for(num = n; num>0; num/=10){
            sum += (num%10);
            mul *= (num%10);
        }
        if (sum == mul)
            return 1;
        else
            return 0;
}
int main(void){
    int x;

    scanf("%d", &x);
    if (is_happy_number(x))
        printf ("YES\n");
    else
        printf ("NO\n");
    return 0;
}
