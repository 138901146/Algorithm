#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

int **adjacent_list=NULL, *adjacent_list_count=NULL, *matched=NULL;
bool *searched=NULL;

bool dfs(int current)
{
	for(int i=0;i<adjacent_list_count[current];++i)
	{
		int next=adjacent_list[current][i];

		if(!searched[next])
		{
			searched[next]=true;

			if(!matched[next] || dfs(matched[next]))
			{
				matched[next]=current;
				return true;
			}
		}
	}

	return false;
}

int main(void)
{
	int N, M, *G=NULL, *B=NULL, *L=NULL, *U=NULL, couple=0;

	scanf("%d%d", &N, &M);
	G=(int *)malloc((N+1)*sizeof(int));
	B=(int *)malloc((M+1)*sizeof(int));
	L=(int *)malloc((N+1)*sizeof(int));
	U=(int *)malloc((M+1)*sizeof(int));

	for(int i=1;i<=N;++i)
		scanf("%d", &G[i]);
	for(int i=1;i<=M;++i)
		scanf("%d", &B[i]);
	for(int i=1;i<=N;++i)
		scanf("%d", &L[i]);
	for(int i=1;i<=M;++i)
		scanf("%d", &U[i]);

	adjacent_list=(int **)malloc((N+1)*sizeof(int *));
	adjacent_list_count=(int *)calloc(N+1,sizeof(int));

	for(int n=1;n<=N;++n)
	{
		for(int m=1;m<=M;++m)
			if(G[n]>U[m] && B[m]<L[n])
				++adjacent_list_count[n];

		adjacent_list[n]=(int *)malloc(adjacent_list_count[n]*sizeof(int));
		adjacent_list_count[n]=0;

		for(int m=1;m<=M;++m)
			if(G[n]>U[m] && B[m]<L[n])
				adjacent_list[n][adjacent_list_count[n]++]=m;
	}

	free(G);
	free(B);
	free(L);
	free(U);
	searched=(bool *)malloc((M+1)*sizeof(bool));
	matched=(int *)calloc(M+1,sizeof(int));

	for(int n=1;n<=N;++n)
	{
		for(int m=1;m<=M;++m)
			searched[m]=false;
		couple+=dfs(n);
	}

	printf("%d", couple);
	while(N)
		free(adjacent_list[N--]);
	free(adjacent_list);
	free(adjacent_list_count);
	free(searched);
	free(matched);
	return 0;
}