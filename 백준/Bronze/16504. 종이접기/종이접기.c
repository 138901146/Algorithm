#include<stdio.h>

int main(void)
{
	long int sum=0, N;
	int K;

	scanf("%ld", &N);

	for(long int n=0;n<N*N;n++)
	{
		scanf("%d", &K);
		sum+=K;
	}

	printf("%ld\n", sum);
	return 0;
}