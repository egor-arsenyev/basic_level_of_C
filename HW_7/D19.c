#include <stdio.h>

int acounter(void){
	char c;
    if ((c = getchar())=='.')
		return 0;
	return ((c == 'a') ? 1 : 0) + acounter();
}

int main(void){

	printf ("%d\n", acounter());

    return 0;
}
