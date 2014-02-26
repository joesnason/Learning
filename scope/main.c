#include <stdio.h>

int num =50; // Global variable
void count(void);

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
	
	printf("\n");
	x = 0;
	for (;x<5;x++){
		count();
	}

	extern double anotherVar; // the value var is set in another.c
	printf("the another Var is %f\n",anotherVar);

	anotherVar = 100;  // we still can change the value
	printf("the another Var become %f\n", anotherVar);
	return 0;
}


void count(void) {
	static int counter = 0; // static variable, when variable be created, it would keep to save in memory.
	printf("the static counter is %d\n", counter);
	counter++;

}
