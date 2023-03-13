#include<stdio.h>
#include<stdlib.h>

int *set=NULL;

int find_set(int x)
{
	if(x==set[x])
		return x;
	else
		return set[x]=find_set(set[x]);
}

void union_set(int x,int y)
{
	if(find_set(x)!=find_set(y))
		set[find_set(y)]=find_set(x);
}

int main(void)
{
	int N, M, *A=NULL, i, j, count=0;

	scanf("%d%d", &N, &M);
	set=(int *)malloc((N+1)*sizeof(int));
	for(int n=0;n<=N;n++)
		set[n]=n;
	A=(int *)malloc(N*sizeof(int));

	for(int m=0;m<M;m++)
	{
		scanf("%d%d", &i, &j);
		union_set(i,j);
	}

	for(int n=0;n<N;n++)
	{
		scanf("%d", &A[n]);
		A[n]=find_set(A[n]);
	}

	for(int n=1;n<N;n++)
		if(A[n-1]!=A[n])
			count++;

	printf("%d\n", count);
	free(A);
	free(set);
	return 0;
}