#include<stdio.h>

int main(void)
{
	int c, e, f, count=0;

	scanf("%d %d %d", &e, &f, &c);

	e+=f;
	while(e>=c)
	{
		count+=e/c;
		e=e%c+e/c;
	}

	printf("%d\n", count);
	return 0;
}