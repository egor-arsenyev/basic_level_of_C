#include <stdio.h>

int main(void){
    int month;

    printf("input a month number:\n");
    scanf("%d", &month);
    if (month<13){
        month = month/3;
        switch (month){
            case 0: printf ("winter\n");
                break;
            case 1: printf ("spring\n");
                break;
            case 2: printf ("summer\n");
                break;
            case 3: printf ("autumn\n");
                break;
            case 4: printf ("winter\n");
        }
    }
    else
        printf ("there's no such thing as a month with that number\n");
    return 0;
}
