#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct employees { //Saves data about employee info
	int id;
	char surname[50];
	int projects;
	char job[50];
};
void codersinfo(int size,struct employees emp[]) { /*Shows the amount of coders that have done more than 10 projects and puts
													their information in a file named "coders.txt*/
	int d,count;
	FILE *fp;
	fp=fopen("coders.txt","w"); 
	for(d=0;d<size;d++) {
		if((emp[d].projects>10) && (strcmp(emp[d].job,"Coder")==0)) { /*Checks if their job is "Coder" and if they've done more 
																		than 10 projects. If true,it prints them in a file*/
			fprintf(fp,"%d %s %d %s\n", emp[d].id, emp[d].surname, emp[d].projects, emp[d].job);
			count++;
		}
	}
	fclose(fp);
	printf("\n");
	printf("%d coders have worked on more than 10 projects.\n\n",count); /*Shows the amount of workers with more than 10 projects
																		 in code*/
}																			
void sortemployees(int size,struct employees emp[]) { /* Sorts the amount of employees according to the amount of projects
														they have done*/
	int d,e,max,max_no;
	for(d=0;d<size;d++) {
		max=0;
		for(e=0;e<size;e++) { //Sets the highest project amount and its number (excluding the previously written ones)
			if(emp[e].projects>max) {
				max=emp[e].projects;
				max_no=e;
			}
		}
		printf("%s			%d\n", emp[max_no].surname, emp[max_no].projects);
		emp[max_no].projects=0;
	}
}
int main() {
	int size,c;
	printf("Enter the amount of employees: ");
	scanf("%d",&size); //Saves the amount of employees
	struct employees emp[size];
	printf("Enter id,surname,number of projects and job of %d employees:\n",size);
	for(c=0;size>c;c++) { //Saves the data of each individual employee
		scanf("%d %s %d %s", &emp[c].id, &emp[c].surname, &emp[c].projects, &emp[c].job);
	}
	codersinfo(size,emp);
	printf("Sorted list of employees according to the number of their projects:\n");
	printf("Surname			Number Of Projects\n");
	printf("-------------------------------------------\n");
	sortemployees(size,emp);
	return(0);
}
