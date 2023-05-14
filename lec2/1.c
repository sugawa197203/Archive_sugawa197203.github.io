#include <stdio.h>

int main(void)
{
	int a = 10;
	int *p = &a;

	printf("a = %d\n", a);
	printf("Address is : %p\n", p);
	printf("Address decimal number : %u\n", p);
}