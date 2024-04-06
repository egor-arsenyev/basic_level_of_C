#include <stdio.h>

int input (int *arr, int n){
    int i;
    for (i = 0; i < n; i++)
        scanf ("%d", &arr[i]);
    return i;
}

void arrPrint(int *arr, int len){
    for (int i = 0; i < len; i++)
        printf("%d ",arr[i]);;
}

void reverseArray(int * array, int num){
    for ( int i = 0, j = num - 1; i < j; i++, j--){
        int t = array[i];
        array[i] = array[j];
        array[j] = t;
    }
}

int main (void){
    enum {ARR_SIZE = 10};
    int arr [ARR_SIZE] = {0};

    input (arr, ARR_SIZE);
    for(int i=0; i<2; i++)
        reverseArray(arr + i*ARR_SIZE/2, ARR_SIZE/2);
    arrPrint(arr, ARR_SIZE);

    return 0;
}
