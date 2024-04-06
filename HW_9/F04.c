#include <stdio.h>

void print_digit(char s[]){

    int res[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i=0;s[i]!=0;i++)
        if ((s[i]>='0')&&(s[i]<='9'))
            res[s[i] - '0']++;

    for (int i = 0; i < 10; i++)
        if (res[i] > 0)
            printf("%d %d\n", i, res[i]);
}

int main(){
    enum {BUFFER_SIZE = 1000};
    char buffer[BUFFER_SIZE];

    scanf("%[^\n]", buffer);
    print_digit(buffer);

    return 0;
}
