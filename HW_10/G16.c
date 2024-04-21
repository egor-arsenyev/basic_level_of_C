#include <stdio.h>
#include <string.h>
#define SIZE 10001

int main(void){
    FILE *in;
    FILE *out;
    char str[SIZE]={0}, strFinal[SIZE]={0};

    in = fopen("input.txt", "r");
    while(fscanf(in, "%[^\n]", str) == 1);
    fclose(in);

    int count = 0;
    for(int i = 0; i < strlen(str); i++){
        if(!memcmp(str+i,"Ling",4)){
            strcat(strFinal, "Cao");
            count += 3;
            i += 4;
        }
        strFinal[count++] = str[i];
    }

    out = fopen("output.txt", "w");
    fprintf(out, "%s", strFinal);
    fclose(out);

    return 0;
}
