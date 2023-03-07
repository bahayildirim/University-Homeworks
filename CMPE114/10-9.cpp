#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	char string[100];
	int length,i;
	printf("Please enter a line: ");
	gets(string);
	length=strlen(string);
	for(i=0;i<length;i++) {
		if(string[i]==' ')
			string[i]='*';
	}
	printf("Line with asterisks: %s",string);
	return(0);
}
