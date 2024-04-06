#include <stdio.h>

int input (int *arr, int n){
    int i;
    for (i = 0; i < n; i++)
        scanf ("%d", &arr[i]);
    return i;
}

void onlyOnce(int* arr, int n){
    int cnt = 0;

    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (arr[i] == arr[j])
                cnt++;
        }
        if (cnt == 1){
            printf ("%d ", arr[i]);
        }
        cnt = 0;
    }
}

int main (void){
    enum {ARR_SIZE = 10};
    int arr [ARR_SIZE] = {0};

    input (arr, ARR_SIZE);
    onlyOnce(arr, ARR_SIZE);

    return 0;
}
