#include <stdio.h>
#define MAX_LINE_SIZE 1001

int main(void){
    FILE *fp;
    char * input_fn = "input.txt";
    char * output_fn = "output.txt";
    char buffer[MAX_LINE_SIZE];

    fp = fopen(input_fn, "r");
    fscanf (fp, "%[^\n]", buffer);
    fclose(fp);

    fp = fopen(output_fn, "w");
    for (char *bptr1 = buffer; *bptr1; bptr1++){
        if (*bptr1 != ' ')
            fprintf(fp, "%c", *bptr1);
        for (char *bptr2 = buffer; *bptr2; bptr2++)
            if ((*bptr2 == *bptr1)&&(bptr2!=bptr1))
                *bptr2 = ' ';
    }
    fclose(fp);

    return 0;
}
