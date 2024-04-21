#include <stdio.h>
#include <string.h>
#define MAX_LINE_SIZE 1001

void is_palindrom(int size, char *s){
	int firstOddFlag = 0;
	int cnt = 1;
	
	for (int i = 0; i < size; i++, cnt = 1){
		for (int j = 0; j < size; j++){
			if ((s[j] == s[i])&&(i != j))
				cnt++;
		}
		if (cnt%2){
			if (firstOddFlag){
				printf("NO\n");
				return; 
			}
			firstOddFlag = 1;
		}
	}
	printf("YES\n");	
} 
int main (void){
    FILE *fp;
    char * input_fn = "input.txt";
    char buf[MAX_LINE_SIZE];
    char c;
    int cnt;
    fp = fopen(input_fn, "r");
    for (cnt=0; ((c=fgetc(fp))!=EOF)&&(cnt < MAX_LINE_SIZE);){
        if ((c>='a' && c<='z')||(c>='A' && c<='Z')){
			if (c>='A' && c<='Z')
				c += 32;//convert to lowcase
            buf[cnt++]=c;
            }
    }
    fclose(fp);

    is_palindrom(cnt, buf);
    
    return 0;
}