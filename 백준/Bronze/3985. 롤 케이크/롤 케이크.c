#include<stdio.h>

int main(void)
{
	int L, N, P, K, longest=0, longest_index, *cake=NULL, *actual=NULL, max_index=0;

	scanf("%d", &L);
	cake=(int *)calloc(L+1,sizeof(int));
	scanf("%d", &N);
	actual=(int *)calloc(N+1,sizeof(int));

	for(int n=1;n<=N;n++)
	{
		scanf("%d%d", &P, &K);
		for(int i=P;i<=K;i++)
			if(!cake[i])
			{
				cake[i]=n;
				actual[n]++;
			}
		if(K-P+1>longest)
		{
			longest=K-P+1;
			longest_index=n;
		}
		if(actual[n]>actual[max_index])
			max_index=n;
	}

	printf("%d\n%d\n", longest_index, max_index);
	free(actual);
	free(cake);
	return 0;
}