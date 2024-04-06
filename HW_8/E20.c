#include <stdio.h>

void swapArr(int *arr,int i,int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void bubbleSort(int* arr,int n){
    int noSwap;

    for(int i=n-1; i>=0; i--){
        noSwap = 1;
        for(int j=0; j<i; j++){
            if((arr[j]%10)>(arr[j+1]%10)){
                swapArr(arr,j,j+1);
                noSwap = 0;
            }
        }
    if(noSwap)
        break;}
}

void printDigitsAscending(int n){
    enum {ARR_SIZE = 10}; // 10 is the number of digits in maximum int number
    int arr [ARR_SIZE] = {0};
    int i;

    for (i = 0; n; i++, n/=10)
        arr[i] = n%10;

    bubbleSort(arr, i);

    for (int j = i-1; j >= 0; j--)
        printf("%d ", arr[j]);
}


int main (void){
    int n;
    scanf("%d", &n);

    printDigitsAscending(n);

    return 0;
}
