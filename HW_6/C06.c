#include <stdio.h>

long long unsigned int numberOfGrains(unsigned int cellNumber){
    long long unsigned int grains = (long long unsigned int)1<<(cellNumber-1);
    return grains;
}

int main(){
    unsigned int num;

    scanf ("%d", &num);
    printf("%llu", numberOfGrains(num));
    return 0;
}
