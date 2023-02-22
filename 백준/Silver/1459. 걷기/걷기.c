#include<stdio.h>

int main(void)
{
	long X, Y, W, S;

	scanf("%ld%ld%ld%ld", &X, &Y, &W, &S);
	if(2*W<S)
	{
		printf("%ld\n", W*(X+Y));
		return 0;
	}

	if(X>Y)
	{
		X+=Y;
		Y=X-Y;
		X-=Y;
	}

	if(W>S)
		printf("%ld\n", (X+Y)%2==0?S*Y:S*(Y-1)+W);
	else
		printf("%ld\n", S*X+W*(Y-X));

	return 0;
}