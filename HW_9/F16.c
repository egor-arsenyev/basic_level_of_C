#include <stdio.h>

void cell_color(char s[]){

    if(((unsigned char)(s[0]-'A') > ('H'-'A'))||
            ((unsigned char)(s[1]-'1') > ('8'-'1'))>0)
        return;

    (s[0]+s[1])%2 ? printf("WIHTE"):printf("BLACK");
}

int main(){
    char cellIndex[3];

    scanf ("%s" , cellIndex);
    cell_color(cellIndex);

    return 0;
}
