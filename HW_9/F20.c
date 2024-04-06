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
    int cntEven = 0;
    int cntOdd = 0;
    int tmp;

    for (i = 0; i < n; i++)
        (a[i]%2) ? cntOdd++ : cntEven++;

    if (cntEven > cntOdd){
        for (i =0; i < n; i++){
            if (a[i]%2){
                for (tmp =1; a[i] > 0; a[i]/=10){
                    if (a[i]%10&1)
                        tmp *= a[i]%10;
                }
                a[i] = tmp;
            }
        }
    }
    else{
        for (i =0; i < n; i++){
            if (!(a[i]%2)){
                for (tmp =1; a[i] > 0; a[i]/=10){
                    if (a[i]%2 == 0)
                        tmp *= a[i]%10;
                }
                a[i] = tmp;
            }
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
