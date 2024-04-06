#include <stdio.h>

int input_arr(int a[], int bufSize){
    int i = 0;

    while ((scanf("%d", &a[i]) == 1)&&(a[i]!=0))
        i++;

    return i;
}

int lost_num(int size, int a[]){
    enum {MAX = 1001, MIN = 0};
    int min = MAX;
    int max = MIN;
    int seqSum = 0;
    int arrSum = 0;

    for (int i = 0; i < size; i++){
        if ((a[i] < MIN)&&(a[i] > MAX))
            return 0;
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
        arrSum += a[i];
    }
    seqSum = ((min + max)*(size + 1))/2;

    return seqSum - arrSum;
}


int main(){
    enum {BUFFER_SIZE = 1000};
    int buffer[BUFFER_SIZE]={0};
    int arrSize, result;

    arrSize = input_arr(buffer, BUFFER_SIZE);

    result = lost_num(arrSize, buffer);

    printf("%d", result);

    return 0;
}
