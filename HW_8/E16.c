#include <stdio.h>

int input (int *arr, int n){
    int i;
    for (i = 0; i < n; i++)
        scanf ("%d", &arr[i]);
    return i;
}

int mostOften(int* arr, int n){
    int cnt = 1;
    int maxCnt = 0;
    int num = 0;

    for(int i = 0; i < (n-1); i++){
        for (int j = i+1; j < n; j++){
            if (arr[i] == arr[j])
                cnt++;
        }
        if (cnt > maxCnt){
            maxCnt = cnt;
            cnt = 1;
            num = i;
        }
    }
    return arr[num];
}

int main (void){
    enum {ARR_SIZE = 10};
    int arr [ARR_SIZE] = {0};

    input (arr, ARR_SIZE);
    printf ("%d\n", mostOften(arr, ARR_SIZE));

    return 0;
}
