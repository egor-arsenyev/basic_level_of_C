#include <stdio.h>

int main(void){
    char * input_fn = "input.txt";
    char * output_fn = "output.txt";
    char c, lastC;
    FILE *fp;
    int cnt = 0;
    int num = 0;

    if((fp = fopen(input_fn, "r")) == NULL){
        perror("Error occured while opening input file!");
        return 1;
    }

    fseek (fp, -2, SEEK_END);

    int line_width = ftell(fp);
    int line[line_width];

    lastC = getc(fp);

    fseek (fp, 0, SEEK_SET);

    while(cnt < line_width){
        c = getc(fp);
        if (c == lastC)
            line[num++] = cnt;
        cnt++;
    }

    fclose(fp);

    if((fp = fopen(output_fn, "w")) == NULL){
        perror("Error occured while opening output file!");
        return 1;
    }

    for (int i = 0; i < num; i++){
        if (i){
            fprintf(fp, " ");
            printf(" ");
        }
        fprintf(fp, "%d", line[i]);
        printf("%d", line[i]);        

    }
    fclose(fp);
    return 0;
}
