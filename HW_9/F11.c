#include <stdio.h>
#include <limits.h>

int input_arr(int bufSize, int a[]){
    int i = 0;

    while (scanf("%d", &a[i]) == 1)
        i++;

    return i;
}

void print_min_sum(int size, int a[]){
    int num1 = 0, num2 = 1;

    for(int i = 1; i < size; i++){
        if (a[i] <= a[num2]){
            if(a[i] <= a[num1]){
                num2 = num1;
                num1 = i;
            }
            else
                num2 = i;
        }
    }
    num1 < num2 ? printf("%d %d", num1, num2) : printf("%d %d", num2, num1);
}

int main(){
    enum {BUFFER_SIZE = 1000};
    int buffer[BUFFER_SIZE]={0};
    int arrSize;

    arrSize = input_arr(BUFFER_SIZE, buffer);
    print_min_sum(arrSize, buffer);

    return 0;
}

