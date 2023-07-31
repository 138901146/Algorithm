#include<stdio.h>
#include<malloc.h>

int N, **count=NULL;

int solution(int left,int K)
{
	if(K<0 || K==0 && left>0)
		return 0;
	if(K>=0 && left==0)
		return 1;
	else if(left<0)
		return 0;
	else if(count[left][K]>=0)
		return count[left][K];

	count[left][K]=0;
	int min=N<left?N:left;
	for(int i=0;i<=min;i++)
		count[left][K]=(count[left][K]+solution(left-i,K-1))%1000000000;

	return count[left][K];
}

int main(void)
{
	int K;

	scanf("%d%d", &N, &K);
	count=(int **)malloc((N+1)*sizeof(int *));
	for(int n=0;n<=N;n++)
	{
		count[n]=(int *)malloc((K+1)*sizeof(int));
		for(int k=0;k<=K;k++)
			count[n][k]=-1;
	}

	printf("%d\n", solution(N,K));
	for(int n=0;n<=N;n++)
		free(count[n]);
	free(count);
	return 0;
}