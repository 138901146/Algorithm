#include<stdio.h>

int main(void)
{
	int X, N, a, b;

	scanf("%d", &X);

	scanf("%d", &N);
	for(int n=0;n<N;n++)
	{
		scanf("%d%d", &a, &b);
		X-=a*b;
	}

	printf("%s\n", X==0?"Yes":"No");
	return 0;
}