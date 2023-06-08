#include <stdio.h>

int main(void)
{
	char ac[] = "abc";
	char *acp = ac;

	for(int i = 0; i < 3; i++){
		printf("Address char is : %c\n", *acp);
		acp++;
	}

	short as[] = {1, 2, 3, 4, 5};
	short *asp = as;

	for(int i = 0; i < 5; i++){
		printf("Address char is : %d\n", *asp);
		asp++;
	}



	long al[] = {1, 2, 3, 4, 5};
	long *alp = alp;

	for(int i = 0; i < 5; i++){
		printf("Address char is : %d\n", *alp);
		alp++;
	}
}