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
    int shiftNum = 4;

    input (arr, ARR_SIZE);
/*реализация через сдвиг одного элемента массива*/
/*
    for (int i; i <= shiftNum; i++)
        shiftOne(arr, ARR_SIZE);
*/
/*реализация через реверс элементов массива*/
    reverseArray (arr, shiftNum);
    reverseArray (arr + shiftNum, ARR_SIZE - shiftNum);
    reverseArray (arr, ARR_SIZE);

    arrPrint(arr, ARR_SIZE);

    return 0;
}
