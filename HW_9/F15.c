#include <stdio.h>
#include <limits.h>
#define BYTE 8

int abs (int val){
    unsigned int absVal;
    int const mask = val >> sizeof(int)*BYTE - 1;
    absVal = (val + mask) ^ mask;
    return absVal;
}

int input_arr(int bufSize, int a[]){
    int i = 0;

    while (scanf("%d", &a[i]) == 1)
        i++;

    return i;
}

int count_bigger_abs(int n, int a[]){
    int max = INT_MIN;
    int cnt = 0;

    for (int i = 0; i < n; i++){
        if (a[i] > max)
            max = a[i];
    }
    for (int i = 0; i < n; i++){
        if ((abs(a[i]) > max)&&(a[i] != max))
            cnt++;
    }

    return cnt;
}

int main(){
    enum {BUFFER_SIZE = 1000};
    int buffer[BUFFER_SIZE]={0};
    int arrSize;

    arrSize = input_arr(BUFFER_SIZE, buffer);
    printf("%d\n", count_bigger_abs(arrSize, buffer));

    return 0;
}

