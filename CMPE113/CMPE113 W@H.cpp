#include <stdio.h>
void printLine(int blanks,int stars);
void printPattern(int lines);
void printPatternModified(int lines, int direction);

int main () {
	int line,direction;
	printf("Input the amount of lines:");
	scanf("%d",&line);
	printf("Input the direction:");
	scanf("%d",&direction);
	printPatternModified(line,direction);
	direction=direction*-1;
	printPatternModified(line,direction);
	return(0);
}

void printPatternModified(int lines,int direction) {
	int c;
	for (c=0;c<lines;c++) {
	if (direction>0)
	printLine(lines-c-1,c+1);
	else
	printLine(c+1,lines-c-1);
	}
}

void printPattern(int lines) {
	int c;
	for (c=0;c<lines;c++) {
		printLine(lines-c-1,c+1);
	}
}

void printLine(int blanks,int stars) {
	int col;
	for (col=0;col<blanks+stars;col++) {
		if (blanks>col)
		printf(" ");
		else
		printf("*");
	}
	printf("\n");
}
