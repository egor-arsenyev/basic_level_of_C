#include <stdio.h>

void print_num(int a, int b){
    printf("%d ", a);
    if (a < b)
        print_num(a + 1, b);
    else if (a > b)
        print_num(a - 1, b);
    else return 0;
}
int main(){
    int x, y;

    scanf("%d%d", &x, &y);
    print_num(x, y);

    return 0;
}
