#include<stdio.h>

int main(void)
{
	int N, X[1000], ez=1001, hard=0;

	scanf("%d", &N);

	for(int i=0;i<N;++i)
	{
		scanf("%d", &X[i]);
		ez=X[i]<ez?X[i]:ez;
		hard=hard<X[i]?X[i]:hard;
	}

	if(X[0]==ez)
		printf("ez");
	else if(X[0]==hard)
		printf("hard");
	else
		printf("?");
	return 0;
}