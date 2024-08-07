#include<stdio.h>

int main(void)
{
	int a, b, c;

	scanf("%d%d%d", &a, &b, &c);

	if(!a)
	{
		c*=c;
		for(int i=0;;++i)
			if(i+b==c)
			{
				printf("%d", i);
				break;
			}
	}
	else if(!b)
	{
		c*=c;
		for(int i=0;;++i)
			if(a+i==c)
			{
				printf("%d", i);
				break;
			}
	}
	else
	{
		for(int i=0;;++i)
			if(a+b==i*i)
			{
				printf("%d", i);
				break;
			}
	}

	return 0;
}