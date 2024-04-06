#include <stdio.h>

int main (void){
    int n;

    scanf("%d", &n);

    for (int i = 2; i < 10; i++)
        printf("%d %d\n", i, n/i);

    return 0;
}
