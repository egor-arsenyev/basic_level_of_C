#include <stdio.h>

void print_num(int n){
    if (n > 0){
        print_num(n/10);
        printf ("%d ", n%10);
    }
}
int main(void){
    int x;

    scanf("%d", &x);

    print_num(x);

    return 0;
}
