#include <stdio.h>

int main(void){
    int x1, y1, x2, y2;//y=k*x+b
    float k, b;

    printf("enter the coordinates of the two points in X Y format:\n");
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    k = (float)(y2 - y1)/(float)(x2 - x1);//calculate the angle of inclination of the line
    b = (float)(y1-k*x1);//calculate the free term of the equation
    printf ("%.2f %.2f\n", k, b);

    return 0;
}
