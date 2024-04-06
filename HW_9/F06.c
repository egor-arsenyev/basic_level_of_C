#include <stdio.h>

int input_arr(int a[], int bufSize){
    int i = 0;

    while (scanf("%d", &a[i]) == 1)
        i++;

    return i;
}

int is_two_same(int size, int a[]){
    for (int i = 0; i < size; i++){
        for (int j = i+1; j < size; j++){
            if (a[i]==a[j]){
                return 1;
            }
        }
    }
    return 0;
}

void print_res (int res){
    res ? printf("YES"):printf("NO");
}

int main(){
    enum {BUFFER_SIZE = 1000};
    int buffer[BUFFER_SIZE]={0};
    int arrSize, result;


    arrSize = input_arr(buffer, BUFFER_SIZE);

    result = is_two_same(arrSize, buffer);

    print_res(result);

    return 0;
}
