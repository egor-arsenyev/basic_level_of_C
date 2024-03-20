#include <stdio.h>

long long int factorial (int n){
    long long int fact = 1;
    for (int i = 1; i<=n; i++)
        fact *= i;
    return fact;

}

int main(){
    unsigned int num;

    scanf ("%d", &num);
    printf("%lld", factorial(num));
    return 0;
}
