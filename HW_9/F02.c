#include <stdio.h>

int input(int arr[], int n){
    int num;
    int i = 0;

    while(scanf("%d",&num)==1)
        arr[i++] = num;
    return i;
}

void arrPrint(int arr[], int len){
    for (int i = 0; i < len; i++)
        printf("%d ",arr[i]);
}

void sort_even_odd (int n, int a[]){
    int i = 0;
    int j = 0;
    int k = 0;
    int tmp;

    for (i = 0; i < n; i++){
        if (!(a[i]%2)){
            tmp = a[i];
            for (j = i; j > k; j--){
                a[j] = a[j-1];
            }
            a[k] = tmp;
            k++;
        }
    }
}


int main (void){
    enum {ARR_SIZE = 20};
    int arr [ARR_SIZE] = {0};
    int num;

    num = input (arr, ARR_SIZE);
    sort_even_odd(num, arr);
    arrPrint(arr, num);

    return 0;
}
