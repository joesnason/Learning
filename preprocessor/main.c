#include <stdio.h>
#include "main.h"

#include "another.h"
#define MAXNUMBER 200;


int main(void){

	my_printf();
}


int my_printf(void){

	printf("Hello World\n");

	int x;
	int num = MAXNUMBER;

	x = my_add(3,5);

	printf("get number: %d\n",x);
	printf("get max number: %d\n", num);
	return 0;
}
