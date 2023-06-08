#include <stdio.h>

int main(void)
{
	char c = 'a';
	char ac[] = "abc";
	char *cp = &c;
	char *acp = ac;

	printf("c = %c\n", c);
	printf("Address is : %p\n", cp);
	printf("Address decimal number : %u\n", cp);

	for(int i = 0; i < 3; i++){
		printf("Address char is : %p\n", &ac[i]);
	}



	short s = 1;
	short as[] = {1, 2, 3, 4, 5};
	short *sp = &s;
	short *asp = as;

	printf("s = %d\n", s);
	printf("Address is : %p\n", sp);
	printf("Address decimal number : %u\n", sp);

	for(int i = 0; i < 5; i++){
		printf("Address char is : %p\n", &as[i]);
	}



	long l = 1;
	long al[] = {1, 2, 3, 4, 5};
	long *lp = &l;
	long *alp = alp;

	printf("l = %d\n", l);
	printf("Address is : %p\n", lp);
	printf("Address decimal number : %u\n", lp);

	for(int i = 0; i < 5; i++){
		printf("Address char is : %p\n", &al[i]);
	}
}