#include <stdio.h>

int main(void){
    char * input_fn = "input.txt";
    char * output_fn = "output.txt";
    FILE *fp;
    char s1[100] = {0};
    char s2[100] = {0};
    char res[100] = {0};
    int i=0;
    int flag = 0;

    if((fp = fopen(input_fn, "r")) == NULL){
        perror("Error occured while opening input file!");
        return 1;
    }

    fscanf(fp, "%s%s", s1, s2);

    for (char* p = s1; *p; p++, flag = 0){
        for (char* q = s1; *q; q++){
            if ((*p == *q)&&(p!=q)){
                flag = 1;
                break;
            }
        }
        if (!flag)
            res[i++] = *p;
    }

    for (char *p = s2, flag = 0; *p; p++, flag = 0){
        for (char* q = s2; *q; q++){
            if ((*p == *q)&&(p!=q)){
                flag = 1;
                break;
            }
        }
        if (!flag)
        res[i++] = *p;
    }

    fclose(fp);

    for(int k = 1; k<i; k++){
        for(int j=0; j<i-1; j++){
            if(res[k]<res[j]){
                int tmp = res[k];
                res[k] = res[j];
                res[j] = tmp;
            }
        }
    }

    if((fp = fopen(output_fn, "w")) == NULL){
        perror("Error occured while opening output file!");
        return 1;
    }

    for (int k = 0; k < i; k++){
        if (res[k]==res[k+1])
            fprintf(fp, "%c ", res[k]);


    }

    fclose(fp);

    return 0;
}
