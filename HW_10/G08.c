#include <stdio.h>
#define MAX_ARR_SIZE 1001

int main(void){
    FILE *fp;
    char * input_fn = "input.txt";
    char * output_fn = "output.txt";
    char c;
    int num = 0;
    int intArr[MAX_ARR_SIZE];

    fp = fopen(input_fn, "r");

    int arrSize = 0;
    int flag = 0;
    do{
        c = fgetc(fp);
        if (c>='0' && c<='9'){
            flag = 1;
            num = num*10 + (int)(c - '0');
        }
        else if (flag == 1){
            intArr[arrSize++] = num;
            flag = 0;
            num = 0;
        }
    }while ((c!=EOF)&&(c!='\n')&&(arrSize<MAX_ARR_SIZE));

    fclose(fp);

    for(int i=arrSize-1; i>=0; i--){
        for(int j=0; j<i; j++){
            if(intArr[j]>intArr[j+1]){
                int tmp = intArr[j];
                intArr[j] = intArr[j+1];
                intArr[j+1] = tmp;
            }
        }
    }

    fp = fopen(output_fn, "w");
    for (int i = 0; i<arrSize; i++){
        fprintf(fp, "%d ", intArr[i]);
    }
    fclose(fp);

    return 0;
}
