#include <stdio.h>

int input (int arr[], int n){
    int i;
    for (i = 0; i < n; i++)
        scanf ("%d", &arr[i]);
    return i;
}

int posSum (int arr[], int len){
    int sum = 0;
    for (int i = 0; i < len; i++)
        if (arr[i] > 0)
            sum += arr[i];
    return sum;
}

int main (void){
    enum {BUFFER_SIZE = 10};
    int buffer [BUFFER_SIZE];

    input (buffer, BUFFER_SIZE);

    printf ("%d\n", posSum (buffer, BUFFER_SIZE));

    return 0;
}
