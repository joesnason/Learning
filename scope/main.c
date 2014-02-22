#include <stdio.h>

int num =50;
int main(void){

	printf("the numbie is %d\n", num);
	int x = 0;
	int num=10;
	for (;x<2;x++) {
		num = num + x;
		printf("the number in for loop is %d\n",num);
	}
	return 0;
}
