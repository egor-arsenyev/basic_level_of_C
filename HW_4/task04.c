#include <stdio.h>

int main(void){
    int a, b, c, d, e, max, min;

    printf("input five numbers:\n");
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

    max =  a > b ?  a : b;
    max = max > c ? max: c;
    max = max > d ? max: d;
    max = max > e ? max: e;

    min =  a < b ?  a : b;
    min = min < c ? min: c;
    min = min < d ? min: d;
    min = min < e ? min: e;

    printf ("%d\n", min+max);

    return 0;
}
