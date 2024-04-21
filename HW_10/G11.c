#include <stdio.h>
#include <string.h>
#define MAX_LINE_SIZE 1001

int main(void){
    FILE *fp;
    char * input_fn = "input.txt";
    char * output_fn = "output.txt";
    char buf[MAX_LINE_SIZE];
    int cnt=0;

    fp = fopen(input_fn, "r");
    while(fscanf(fp,"%s",buf)==1){
        int len = strlen(buf);
        if (buf[len-1] == 'a')
            cnt++;
        }
    fclose(fp);

    fp = fopen(output_fn, "w");
    fprintf(fp, "%d", cnt);
    fclose(fp);

    return 0;
}
