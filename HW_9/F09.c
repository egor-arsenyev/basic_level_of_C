#include <stdio.h>
#include <limits.h>

int input_arr(int a[], int bufSize){
    int i = 0;

    while (scanf("%d", &a[i]) == 1)
        i++;

    return i;
}

void arrPrint(int size, int a[]){
    for (int i = 0; i < size; i++)
        printf("%d ",a[i]);
}

void swap_negmax_last(int size, int a[]){
    int maxNeg = INT_MIN;
    int arrNum = -1;
    int tmp;

    for (int i = 0; i < size; i++){
        if (a[i] < 0){
            if (a[i] > maxNeg){
                maxNeg = a[i];
                arrNum = i;
            }
        }
    }
    if (arrNum > -1){
        tmp = a[arrNum];
        a[arrNum] = a[size-1];
        a[size-1] = tmp;
    }
}


int main(){
    enum {BUFFER_SIZE = 1000};
    int buffer[BUFFER_SIZE]={0};
    int arrSize;

    arrSize = input_arr(buffer, BUFFER_SIZE);
    swap_negmax_last(arrSize, buffer);
    arrPrint(arrSize, buffer);

    return 0;
}

