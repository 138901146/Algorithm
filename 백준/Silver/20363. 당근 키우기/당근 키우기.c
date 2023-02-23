#include<stdio.h>

int main(void)
{
	int X, Y;

	scanf("%d %d", &X, &Y);

	if(X<Y)
	{
		int temp=X;
		X=Y;
		Y=temp;
	}

	printf("%d\n", X+Y/10+Y);
	return 0;
}