#include<stdio.h>

int main(void)
{
	int number, password=0;

	for(int i=2;0<=i;--i)
	{
		scanf("%d", &number);
		password|=(number&15)<<(i<<2);
	}

	printf("%04d", password);
	return 0;
}