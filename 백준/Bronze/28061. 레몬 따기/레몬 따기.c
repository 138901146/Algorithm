#include<stdio.h>

int main(void)
{
	int N, a, max=0, lemon;

	scanf("%d", &N);

	for(int i=0;i<N;++i)
	{
		scanf("%d", &a);

		lemon=a+i-N<0?0:a+i-N;
		max=lemon<max?max:lemon;
	}

	printf("%d", max);
	return 0;
}