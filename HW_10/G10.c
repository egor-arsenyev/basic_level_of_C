#include <stdio.h>
#include <string.h>
#define MAX_LINE_SIZE 1001

int main(void){
    FILE *fp;
    char * input_fn = "input.txt";
    char * output_fn = "output.txt";
    char s[MAX_LINE_SIZE];
    char smax[MAX_LINE_SIZE];
    int maxLen = 0;

    fp = fopen(input_fn, "r");
    int len;
    while(fscanf (fp, "%s", s) == 1){
        len = strlen(s);
        if (len > maxLen){
            strcpy(smax,s);
            maxLen = len;
        }
    };
    fclose(fp);

    fp = fopen(output_fn, "w");
    fprintf(fp, "%s", smax);
    fclose(fp);

    return 0;
}