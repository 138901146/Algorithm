#include<stdio.h>

int main(void)
{
	char c;

	while(1)
	{
		c=getchar();
		if(c=='.')
			break;
		putchar(c);
	}

	return 0;
}