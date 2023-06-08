#include <stdio.h>

int main(void)
{
	int a[] = {1, 2, 3, 4, 5};
	int *p = a;
	int *p0 = &a[0];
	int *p1 = &a[1];
	int *p2 = &a[2];
	int *p3 = &a[3];
	int *p4 = &a[4];

	printf("a is : %p\n", p);
	printf("a0 is : %p\n", p0);
	printf("a1 is : %p\n", p1);
	printf("a2 is : %p\n", p2);
	printf("a3 is : %p\n", p3);
	printf("a4 is : %p\n", p4);
}