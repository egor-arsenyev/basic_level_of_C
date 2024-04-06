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

void shiftOne(int * array, int num){
    int tmp;

    tmp = array[num -1];
    for ( int i = (num-1); i > 0; i--){
        array [i] = array[i-1];
    }
    array[0] = tmp;
}


int main (void){
    enum {ARR_SIZE = 10};
    int arr [ARR_SIZE] = {0};

    input (arr, ARR_SIZE);
    shiftOne(arr, ARR_SIZE);
    arrPrint(arr, ARR_SIZE);

    return 0;
}
