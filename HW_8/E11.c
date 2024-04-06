#include <stdio.h>

int input (int *arr, int n){
    int i;
    for (i = 0; i < n; i++)
        scanf ("%d", &arr[i]);
    return i;
}

void arrPrint(int *arr, int len){
    for (int i = 0; i < len; i++)
        printf("%d ",arr[i]);;
}

void SwapArr(int *arr,int i,int j)
{
int temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}

void BubbleOnes(int* arr,int n){
    int noSwap;

    for(int i=n-1; i>=0; i--){
        noSwap = 1;
        for(int j=0; j<i; j++){
            if((arr[j]%10)>(arr[j+1]%10)){
                SwapArr(arr,j,j+1);
                noSwap = 0;
            }
        }
    if(noSwap)
        break;}
}



int main (void){
    enum {ARR_SIZE = 10};
    int arr [ARR_SIZE] = {0};

    input (arr, ARR_SIZE);
    BubbleOnes(arr, ARR_SIZE);
    arrPrint(arr, ARR_SIZE);

    return 0;
}
