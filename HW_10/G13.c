#include <stdio.h>
#include <string.h>
#define MAX_LINE_SIZE 1001

int main(void){
    FILE *fp;
    char * input_fn = "input.txt";
    char * output_fn = "output.txt";
    char buf[MAX_LINE_SIZE];
    int slashPos, dotPos = 0;

    fp = fopen(input_fn, "r");
    fscanf (fp, "%s", buf);
    fclose(fp);

    int i;
    int size = strlen(buf);

    for (i = 0; i<size; i++){
        if(buf[i] == '/')
            slashPos = i;
    }
    for (int i = slashPos+1; i<strlen(buf); i++){
        if (buf[i] == '.')
            dotPos = i;
    }
    if (dotPos==0)
        dotPos = i;

    fp = fopen(output_fn, "w");
    for(int i = 0; i < dotPos; i++){
        fprintf(fp, "%c", buf[i]);
    }
    fprintf(fp,".html");

    fclose(fp);

    return 0;
}
