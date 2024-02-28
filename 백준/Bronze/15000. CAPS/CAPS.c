#include<stdio.h>

int main(void)
{
	char c;

	c=getchar();
	while(96<c && c<123)
	{
		putchar(c-32);
		c=getchar();
	}

	return 0;
}