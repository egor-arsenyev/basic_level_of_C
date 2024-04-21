#include <stdio.h>
#define MAX_LINE_SIZE 10001

int main(void){
    FILE *fp;
    char * input_fn = "input.txt";
    char * output_fn = "output.txt";
    char c;
    int lowCaseCnt = 0;
    int upCaseCnt = 0;

    fp = fopen(input_fn, "r");

    for (int i; ((c=fgetc(fp))!=EOF)&&(c != '\n')&&(i < MAX_LINE_SIZE); i++){
        if(c>='a' && c<='z')
            lowCaseCnt++;
        else if(c>='A' && c<='Z')
            upCaseCnt++;
    }
    fclose(fp);

    fp = fopen(output_fn, "w");
    fprintf(fp, "%d %d", lowCaseCnt, upCaseCnt);
    fclose(fp);

    return 0;
}