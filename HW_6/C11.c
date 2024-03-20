#include <stdio.h>

int nod(int a, int b){
    int t;
    while (b != 0){
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main(){
    int num1, num2;

    scanf ("%d%d", &num1, &num2);
    printf("%d", nod(num1, num2));
    return 0;
}
