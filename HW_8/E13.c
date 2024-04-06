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

void selection(int* arr, int n){
    int selectArr[n];
    int j = 0;

    for(int i = 0; i < n; i++){
        if (!((arr[i]%100)/10)){
            selectArr[j] = arr[i];
            j++;
        }
    }
    arrPrint(selectArr, j);
}



int main (void){
    enum {ARR_SIZE = 10};
    int arr [ARR_SIZE] = {0};

    input (arr, ARR_SIZE);
    selection (arr, ARR_SIZE);

    return 0;
}
