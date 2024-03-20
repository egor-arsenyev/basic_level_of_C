#include <stdio.h>

void print_digits(int n){
    if (n > 0){
        print_digits(n/10);
        printf ("%d ", n%10);
    }
}
int main(void){
    int x;

    scanf("%d", &x);

    print_digits(x);

    return 0;
}
