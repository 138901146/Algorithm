#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int weight, value;
}
bag;

int main(void)
{
	int N, K, **knapsack=NULL, max=0;
	bag *js=NULL;

	scanf("%d%d", &N, &K);
	js=(bag *)malloc((N+1)*sizeof(bag));
	knapsack=(int **)malloc((N+1)*sizeof(int *));

	knapsack[0]=(int *)calloc(K+1,sizeof(int));
	for(int n=1;n<=N;n++)
	{
		scanf("%d%d", &js[n].weight, &js[n].value);
		knapsack[n]=(int *)calloc(K+1,sizeof(int));
	}

	for(int n=1;n<=N;n++)
		for(int k=0;k<=K;k++)
			if(js[n].weight<=k)
				knapsack[n][k]=knapsack[n-1][k]>knapsack[n-1][k-js[n].weight]+js[n].value?knapsack[n-1][k]:knapsack[n-1][k-js[n].weight]+js[n].value;
			else
				knapsack[n][k]=knapsack[n-1][k];

	printf("%d\n", knapsack[N][K]);
	for(int n=0;n<=N;n++)
		free(knapsack[n]);
	free(knapsack);
	free(js);
	return 0;
}