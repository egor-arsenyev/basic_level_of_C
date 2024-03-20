#include <stdio.h>

void get_odd(void){
    int num;
    scanf("%d", &num);
    if (num == 0)
        return;
    if (num & 1)
        printf ("%d ", num);
    get_odd();
}

int main()
{
    get_odd();
    return 0;
}
