#include<stdio.h>

int main(void)
{
	int N, K, A, sum=0;

	scanf("%d %d", &N, &K);

	for(int i=0;i<K;i++)
	{
		scanf("%d", &A);
		sum+=A%2==0?A/2:A/2+1;
	}

	printf("%s\n", N<=sum?"YES":"NO");
	return 0;
}