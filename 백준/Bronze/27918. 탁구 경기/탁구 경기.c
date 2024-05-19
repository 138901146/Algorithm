#include<stdio.h>

int abs(int x)
{
	return x<0?-x:x;
}

int main(void)
{
	int N, X=0, Y=0;
	char winner;

	scanf("%d", &N);

	while(N--)
	{
		getchar();
		winner=getchar();

		if(winner=='D')
			++X;
		else
			++Y;

		if(abs(X-Y)==2)
			break;
	}

	printf("%d:%d", X, Y);
	return 0;
}