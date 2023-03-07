#define pi 3.14
#include <stdio.h>
#include <stdlib.h>
double calculateVolume (double radius,double height);
double calculateBaseArea (double radius);
double calculateCircumference (double radius,double height);
double calculatePerimeter (double radius);
int printResults ();
int main ()
{
	printResults();
}

double calculateBaseArea (double radius) {
	double basearea;
	return basearea=pi*radius*radius;
}
double calculatePerimeter (double radius) {
	double perimeter;
	return perimeter=2*pi*radius;
}
double calculateVolume (double radius,double height) {
	double volume;
	return volume=calculateBaseArea(radius)*height;
}
double calculateCircumference (double radius,double height) {
	double circumference;
	return circumference=(calculatePerimeter(radius)*height)+(2*calculateBaseArea(radius));
}
int printResults () {
	double radius,height,loop=1;
	while (loop>0) {
	do {
		printf("Enter radius and height:");
		scanf("%lf %lf",&radius,&height);
		if ((radius==0) || (height==0)) {
			printf("Goodbye!");
			return(0);
	} }
	while ((radius<=0) || (height<=0));	
	printf("Volume of the cylinder is %lf,circumference of the cylinder is %lf\n",calculateCircumference(radius,height),calculateVolume(radius,height));
	printf("New Cylinder\n");
} }
