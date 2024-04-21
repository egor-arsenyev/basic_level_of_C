#include <stdio.h>

int main(void){
    char * input_fn = "input.txt";
    char * output_fn = "output.txt";
    FILE *fp;
    char buf[1000];

    fp = fopen(input_fn, "r");

    fscanf(fp, "%[^\n]", buf);

    fclose(fp);

    fp = fopen(output_fn, "w");

    for (char* p = buf; *p; p++){
        switch (*p){
            case 'a':
                 *p = 'b';
                 break;
            case 'A':
                 *p = 'B';
                 break;
            case 'b':
                 *p = 'a';
                 break;
            case 'B':
            *p = 'A';
        }
     }

    fprintf(fp, "%s", buf);

    fclose(fp);

    return 0;

}
