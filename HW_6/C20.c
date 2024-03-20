#include <stdio.h>

int checkParentheses(void){
    char symbol;
    int cntPar = 0;
    unsigned int firstSymbol = 1;
    unsigned int cntChar = 0;

    do{
        symbol = getchar();
        if (!firstSymbol){
            if (symbol == '(')
                cntPar++;
            else if (symbol == ')')
                cntPar--;
            cntChar++;
            if (cntPar < 0) // detecting "())(()" case
                return 0;
        }
        else{
            if(symbol != '(') //invalid first character detection
                return 0;
            else{
                firstSymbol = 0;
                cntPar++;
                cntChar++;
            }
        }
    }while ((symbol!='.')&&(cntChar<=1000));

    if (cntPar == 0) //detecting inequalities in the number of "(" and  ")"
        return 1;
    else
        return 0;
}

int main(){

    if (checkParentheses())
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
