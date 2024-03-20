#include <stdio.h>
int get_one(int n){
    static int cnt = 0;
    if (n == 0)
        return 0;
    else return (1+get_one(n & (n-1)));

}
int main(){
    int x;

    scanf("%d", &x);
    printf ("%d ", get_one(x));

    return 0;
}
