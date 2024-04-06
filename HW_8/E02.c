#include <stdio.h>

int input (int arr[], int n){
    int i;
    for (i = 0; i < n; i++)
        scanf ("%d", &arr[i]);
    return i;
}

int min (int arr[], int len){
    int min = arr[0], i;
    for (i = 1; i < len; i++)
        if (min > arr[i])
            min = arr[i];
    return min;
}

int main (void){
    enum {BUFFER_SIZE = 5};
    int buffer [BUFFER_SIZE];

    input (buffer, BUFFER_SIZE);

    printf ("%d\n", min (buffer, BUFFER_SIZE));

    return 0;
}

