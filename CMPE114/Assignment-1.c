#include <stdio.h>
#include <stdlib.h>
void polynomial(int size,int polynomial_coeff[]) { //Prints a polynomial function with given size and coefficient values
	int n;
	for(n=size;-1<n;n--) { //Takes the coefficient values n+1 times
		printf("Enter the coefficient of x to the power %d: ",n);
		scanf("%d",&polynomial_coeff[n]); 
	}
	printf("Entered polynomial function:\n");
	printf("f(x)=");
	for(n=size;-1<n;n--) { //Prints the polynomial function
		if ((n==size) && (polynomial_coeff>0)) //Prints nothing if it is the first number and its coefficient is positive
			printf("");
		else if(polynomial_coeff[n]>0) //Prints a + or a - depending on its value
			printf("+"); 
		else
			printf("-");
		if(n>0) //Checks if it is about to print the last coefficient and prints a constant instead if true
			printf("%dx^%d",abs(polynomial_coeff[n]),n); //abs function prevents multiple minuses if a negative number is inputted
		else
			printf("%d",abs(polynomial_coeff[n]));
	}
	printf("\n");
}
int find_derivative(int size,int degree,int polynomial_coeff[]) { //Calculates the derivative by the amount of degrees
	int n,c,a,power,new_coeff[size];
	for(n=size;n>-1;n--) {
		new_coeff[n]=polynomial_coeff[n];
	}
	for(c=0;degree>c;c++,a++) { //Takes the derivative n times depending on the value of degree
		for(n=size;n>-1;n--) { //Derivative calculation
			power=n-a;
			if(power<0) //Sets power to 0 if it is below 0 to prevent negative powers
				power=0;
			new_coeff[n]=new_coeff[n]*power;
		}
	}
	printf("%d. derivative: df(x)=",degree);
	for(n=size;n>-1;n--) { //Prints the nth derivative of a function
		if(new_coeff[n]==0) { //Prints nothing and leaves the function once the last number (0) is reached
			printf("");
			return(0);
	}
		else if (((n==size) && (new_coeff[n]>=0))) //Prints nothing if it is the first number and its coefficient is positive or 0 if the coefficient is 0
			printf("");
		else if(new_coeff[n]>0) //Prints a + or a - depending on its value
			printf("+");
		else
			printf("-");
		if((n>0) && ((n-degree)>0)) //Checks if it is about to print the 2nd last coefficient and prints a constant if true
			printf("%dx^%d",abs(new_coeff[n]),n-degree);
		else
			printf("%d",abs(new_coeff[n]));
	}
}
int main() {
	int size,polynomial_coeff[size];
	printf("Enter the degree of polynomial equation: ");
	scanf("%d",&size);
	polynomial(size,polynomial_coeff);
	int degree;
	printf("Which degree of derivative you want to calculate? ");
	scanf("%d",&degree);
	find_derivative(size,degree,polynomial_coeff);
	return(0);
}
