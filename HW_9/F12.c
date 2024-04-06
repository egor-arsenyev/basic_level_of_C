#include <stdio.h>
#include <limits.h>

int input_arr(int bufSize, int a[]){
    int i = 0;

    while (scanf("%d", &a[i]) == 1)
        i++;

    return i;
}

void arrPrint(int size, int a[]){
    for (int i = 0; i < size; i++)
        printf("%d ",a[i]);
    printf ("\n");
}

void change_max_min(int size, int a[]){
    int min = INT_MAX;
    int max = INT_MIN;
    int tmp;

    for (int i = 0; i < size; i++){
        if (a[i] < min)
            min = i;
        if (a[i] > max)
            max = i;
    }
    tmp = a[min];
    a[min] = a[max];
    a[max] = tmp;
}

int main(){
    enum {BUFFER_SIZE = 1000};
    int buffer[BUFFER_SIZE]={0};
    int arrSize;

    arrSize = input_arr(BUFFER_SIZE, buffer);
    arrPrint (arrSize, buffer);
    change_max_min(arrSize, buffer);
    arrPrint (arrSize, buffer);

    return 0;
}

