#include<stdio.h>

int main(void)
{
	int N, coin, sum=0;

	scanf("%d", &N);
	N<<=1;

	while(N--)
	{
		scanf("%d", &coin);
		sum+=coin<0?-coin:coin;
	}

	printf("%d", sum);
	return 0;
}