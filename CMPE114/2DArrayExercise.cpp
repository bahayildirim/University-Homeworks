#include <stdio.h>
#include <stdlib.h>
int main() {
	int r,c,arr_initial[5][5],arr_new[5][5];
	printf("Enter integers:");
	for(r=0;r<5;r++) {
		for(c=0;c<5;c++) {
			scanf("%d",&arr_initial[r][c]);
		}
	}
	for(r=1;r<4;r++) {
		for(c=1;c<4;c++) {
			arr_new[r][c]=(arr_initial[r+1][c]+arr_initial[r-1][c]+arr_initial[r][c+1]+arr_initial[r][c-1])/4;
		}
	}
	for(r=0;r<5;r++) {
		for(c=0;c<5;c++) {
			if((r==0) || (r==4) || (c==0) || (c==4))
				arr_new[r][c]=0;
		}
	}
	printf("Result:\n");
	for(r=0;r<5;r++) {
		for(c=0;c<5;c++) {
			printf("%d ",arr_new[r][c]);
		}
		printf("\n");
	}
return(0);	
}
