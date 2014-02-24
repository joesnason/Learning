#include <stdio.h>

int num =50; // Global variable
int main(void){

	printf("the numbie is %d\n", num);
	int x = 0; // Local variable
	int num=10;
	for (;x<2;x++) {
		int num = 100; // Block variable
		num = num + x;
		printf("the number in for loop is %d\n",num);
	}
	printf("the local variable is %d\n", num);
	return 0;
}
