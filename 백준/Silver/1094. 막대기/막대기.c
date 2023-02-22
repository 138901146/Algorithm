#include<stdio.h>

int main(void)
{
	int X, size=64, count=0;

	scanf("%d", &X);

	do
	{
		if(size<=X)
		{
			X-=size;
			count++;
		}
		size/=2;
	}
	while(X>0);

	printf("%d\n", count);

	return 0;
}