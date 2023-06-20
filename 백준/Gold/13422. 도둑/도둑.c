#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int N, K, M, *house=NULL, sum=0, count=0;

		scanf("%d%d%d", &N, &M, &K);
		house=(int *)malloc(N*sizeof(int));

		for(int n=0;n<N;n++)
			scanf("%d", &house[n]);

		for(int m=0;m<M;m++)
			sum+=house[m];

		if(N==M)
		{
			printf("%d\n", sum<K);
			free(house);
			continue;
		}

		for(int n=0;n<N;n++)
		{
			sum=sum+house[(n+M)%N]-house[n];
			count+=sum<K;
		}

		printf("%d\n", count);
		free(house);
	}

	return 0;
}