#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int N, K, max=0, candy;

		scanf("%d %d", &N, &K);

		for(int i=0;i<N;i++)
		{
			scanf("%d", &candy);
			max+=candy/K;
		}

		printf("%d\n", max);
	}

	return 0;
}