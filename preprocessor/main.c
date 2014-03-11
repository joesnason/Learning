#include <stdio.h>
#include "main.h"

#include "another.h"
#define MAXNUMBER 200;
#define swap_int(A,B); {int t; \
							t = A; A = B; B = t	;}

#define max(A,B)   ((A>B)?A:B)
#define max3(A,B,C)  (max(max(A,B),C))

int main(void){

	my_printf();
}


int my_printf(void){

	printf("Hello World\n");

	int x;
	int num = MAXNUMBER;
	int big = 100;
	int small = 10;


	x = my_add(3,5);

	printf("get number: %d\n",x);
	printf("get max number: %d\n", num);

// define macro test 
	printf("the big number is %d , the small number is %d \n",big,small);
	swap_int(big,small);
	printf("after to swap.....\n");
	printf("the big number is %d , the small number is %d \n",big,small);

// define macro test
	printf("get the max number %d\n", max(big,small));
	printf("get the max number of three is %d\n", max3(big,small,num));

	return 0;
}
