#include <stdio.h>
#include <string.h>
#define MAX_LINE_SIZE 1001

int main(void){
    FILE *pin;
    FILE *pout;
    char * input_fn = "input.txt";
    char * output_fn = "output.txt";
    char buf[MAX_LINE_SIZE];

    pin  = fopen(input_fn, "r");
    pout = fopen(output_fn, "w");
    while(fscanf(pin, "%s", buf) == 1)
        fprintf (pout, "%s ", buf);
    fclose(pin);
    fclose(pout);
    return 0;
}