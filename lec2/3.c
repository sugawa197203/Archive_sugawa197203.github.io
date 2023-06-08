#include <stdio.h>

int main(void)
{
	int a[] = {1, 2, 3, 4, 5};
	int *p = a;

	for(int i = 0; i < 5; i++){
		printf("%d\n", p[i]);
	}
}