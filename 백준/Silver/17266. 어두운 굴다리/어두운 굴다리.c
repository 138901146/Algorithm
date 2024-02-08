#include<stdio.h>

int main(void)
{
	int N, M, x[2], current=1, previous=0, gap;

	scanf("%d", &N);
	scanf("%d", &M);

	scanf("%d", &x[0]);
	gap=x[0];
	while(--M)
	{
		scanf("%d", &x[current]);
		gap=gap<x[current]-x[previous]+1>>1?x[current]-x[previous]+1>>1:gap;
		current^=1;
		previous^=1;
	}
	gap=gap<N-x[previous]?N-x[previous]:gap;

	printf("%d", gap);
	return 0;
}