#include <stdio.h>

unsigned int sum(unsigned int quantity){
    unsigned int sum = 0;
    for (int i = quantity; i > 0; i-- )
        sum+= i;
    return sum;
}

int main(){
    unsigned int num;

    scanf ("%d", &num);
    printf("%d\n", sum(num));
    return 0;
}
