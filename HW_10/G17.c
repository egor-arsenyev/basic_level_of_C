#include <stdio.h>
#include <string.h>
#define MAX_LINE_SIZE 1001

int main(void){
    FILE *fp;
    char * input_fn = "input.txt";
    char * output_fn = "output.txt";
    char buf[MAX_LINE_SIZE];

    fp = fopen(input_fn, "r");
    fscanf(fp, "%[^\n]", buf);
    fclose(fp);
    
    int i, j;
    int len = strlen(buf);
    for (i=0, j=0; j<len;){
        while (buf[i] == ' ')
            i++;
        j = i+1;
        while(buf[j] == ' ')
            j++;
        if(j>=len)
			break;
        int tmp = buf[j];
        buf[j] = buf[i];
        buf[i] = tmp;
        i=j+1;
    }
    fp = fopen(output_fn, "w");
    fprintf(fp, "%s", buf);
    fclose(fp);

    return 0;
}
