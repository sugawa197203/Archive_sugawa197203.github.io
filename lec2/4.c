#include <stdio.h>

void swap(int a, int b){
	int tmp = a;
	a = b;
	b = tmp;
}

int main(void)
{
	int x, y;
	x = 5;
	y = 3;
	
	printf("x = %d, y = %d\n", x, y);

	swap(x, y);

	printf("x = %d, y = %d\n", x, y);
}