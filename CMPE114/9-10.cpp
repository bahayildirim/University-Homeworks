#include <stdio.h>
#include <stdlib.h>
void calculate (int size,int arr1[],int arr2[],char op);
int main() {
	int size,arr1[size],arr2[size],count,result;
	char op;
	printf("Enter array size:");
	scanf("%d",&size);
	printf("Enter 6 integers:");
	for(count=0;size>count;count++) {
		scanf("%d",&arr1[count]);
	}
	printf("Enter 6 integers:");
	for(count=0;size>count;count++) {
		scanf("%d",&arr2[count]);
	}
	printf("Enter an operator:");
	scanf("%c",&op);
	printf("Result:");
	calculate (size,arr1,arr2,op);
	return(0);
}

void calculate (int size,int arr1[],int arr2[],char op) {
	int c,result;
	for(c=0;size>c;c++) {
		switch(op) {
			case '+': 
				result=arr1[c]+arr2[c];
				break;
			case '-':
				result=arr1[c]-arr2[c];
				break;
			case '*':
				result=arr1[c]*arr2[c];
				break;
		printf(" %d",result);
		}
	}
}
