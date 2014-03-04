#include <stdio.h>
#include "main.h"

#include "another.h"

int main(void){

	my_printf();
}


int my_printf(void){

	printf("Hello World\n");

	int x;

	x = my_add(3,5);

	printf("get number: %d\n",x);
	return 0;
}
