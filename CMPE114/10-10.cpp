#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	char string[100];
	int i,length;
	printf("Please enter a line: ");
	gets(string);
	length=strlen(string);
	for(i=0;i<length;i++) {
		if((64>string[i]) && (string[i]<91))
			string[i]+=32; 
	}
	printf("Line with lowercase letters: \n");
	puts(string);
	return(0);
}
