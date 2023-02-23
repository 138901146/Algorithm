#include<stdio.h>

int main(void)
{
	int C, n;

	scanf("%d", &C);

	for(n=1;C>1;n++)
		C=C%2==0?C/2:3*C+1;

	printf("%d\n", n);
	return 0;
}