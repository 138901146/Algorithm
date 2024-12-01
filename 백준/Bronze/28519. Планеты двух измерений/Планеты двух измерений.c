#include<stdio.h>

int main(void)
{
	int X, Y;

	scanf("%d%d", &X, &Y);

	if(X<Y)
	{
		int temp=X;
		X=Y;
		Y=temp;
	}

	if(Y<X)
		X=Y+1;

	printf("%d", X+Y);
	return 0;
}