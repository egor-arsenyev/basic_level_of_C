#include <stdio.h>

void printDigitsRecursion(int n){
    if (n){
        printDigitsRecursion(n/10);
        printf("%d ", n%10);
    }
}

void printDigitsCycle(int n){
    enum {ARR_SIZE = 10};
    int arr [ARR_SIZE] = {0};
    int i;

    for (i = 0; n; i++, n/=10){
        arr[i] = n%10;
    }
    for (int j = i-1; j >= 0; j--)
        printf("%d ", arr[j]);
}


int main (void){
    int n;
    scanf("%d", &n);

    printDigitsCycle(n);

    return 0;
}
