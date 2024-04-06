#include <stdio.h>

int input_arr(int bufSize, int a[]){
    int i = 0;

    while (scanf("%d", &a[i]) == 1)
        i++;

    return i;
}

int sum_between_ab(int from, int to, int size, int a[]){
    int sum = 0, i = 0;

    while((a[i]!=from)&&(a[i]!=to)&&(i<size-1)){
        i++;
    }

    sum += a[i];

    do{
        sum += a[++i];
    }while((a[i]!=from)&&(a[i]!=to)&&(i<(size-1)));

    return sum;
}

int main(){
    enum {BUFFER_SIZE = 1000};
    int buffer[BUFFER_SIZE]={0};
    int arrSize, from, to;

    scanf ("%d%d", &from, &to);
    arrSize = input_arr(BUFFER_SIZE, buffer);
    printf("%d\n", sum_between_ab(from, to, arrSize, buffer));

    return 0;
}

