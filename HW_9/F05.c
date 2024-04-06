#include <stdio.h>

int input_arr(int a[], int bufSize){
    int i;
    for (i=0; ((scanf("%d", &a[i]))&&(i<(bufSize-1))); i++)
    {}
    return i;
}

int find_max_array(int size, int a[]){
    int max = a[0], i;

    for (i = 1; i < size; i++)
        if (max < a[i])
            max = a[i];

    return max;
}

int main(){
    enum {BUFFER_SIZE = 1000};
    int buffer[BUFFER_SIZE]={0};
    int arrSize;

    arrSize = input_arr(buffer, BUFFER_SIZE);

    printf("%d", find_max_array(arrSize, buffer));

    return 0;
}
