#include <stdio.h>
#include <limits.h>

int input_arr(int bufSize, int a[]){
    int i = 0;

    while (scanf("%d", &a[i]) == 1)
        i++;

    return i;
}

int count_between(int from, int to, int size, int a[]){
    int f,t;

    for (int i = 0; i < size; i++){
        if (a[i] == from)
            f = i;
        if (a[i] == to)
            t = i;
    }
    if (t > f)
        return (t - f + 1);
    else
        return (f - t + 1);
}

int main(){
    enum {BUFFER_SIZE = 1000};
    int buffer[BUFFER_SIZE]={0};
    int arrSize, from, to;

    scanf ("%d%d", &from, &to);
    arrSize = input_arr(BUFFER_SIZE, buffer);
    printf("%d", count_between(from, to, arrSize, buffer));

    return 0;
}

