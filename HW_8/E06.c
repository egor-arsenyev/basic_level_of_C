#include <stdio.h>

int input (int arr[], int n){
    int i;
    for (i = 0; i < n; i++)
        scanf ("%d", &arr[i]);
    return i;
}

float average (int arr[], int len){
    float aver = arr[0];
    for (int i = 1; i < len; i++)
        aver += arr[i];
    aver /= (float)len;
    return aver;
}


int main (void){
    enum {BUFFER_SIZE = 12};
    int buffer [BUFFER_SIZE];

    input (buffer, BUFFER_SIZE);

    printf ("%.2f\n", average (buffer, BUFFER_SIZE));

    return 0;
}
