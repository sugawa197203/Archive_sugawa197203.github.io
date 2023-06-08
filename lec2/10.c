#include <stdio.h>

int main(void)
{
	int a = 334;
	int *ap = &a;

	printf("a Address is %p\n", ap);
	printf("a = %d\n", a);
	printf("a = %d\n", *ap);

	ap = 114514;

	printf("a = %d\n", a);
	printf("a = %d\n", *ap);
}