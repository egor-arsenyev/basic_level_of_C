#include <stdio.h>
#define MAX_LINE_SIZE 101

int main(void){
    FILE *fp;
    char * input_fn = "input.txt";
    char * output_fn = "output.txt";
    char name[MAX_LINE_SIZE];
    char lastName[MAX_LINE_SIZE];

    fp = fopen(input_fn, "r");
    fscanf(fp,"%s",lastName);
    fscanf(fp,"%s",name);
    fclose(fp);

    fp = fopen(output_fn, "w");
    fprintf(fp, "Hello, %s %s!", name, lastName);
    fclose(fp);

    return 0;
}
