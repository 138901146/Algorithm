#include<stdio.h>
#include<malloc.h>

int *set=NULL, *A=NULL;

int find_set(int x)
{
	if(x==set[x])
		return x;
	else
		return set[x]=find_set(set[x]);
}

void union_set(int x,int y)
{
	int parent_x=find_set(x), parent_y=find_set(y);

	if(parent_x!=parent_y)
	{
		if(A[parent_x]>A[parent_y])
			set[find_set(x)]=find_set(y);
		else
			set[find_set(y)]=find_set(x);
	}
}

int main(void)
{
	int N, M, k, sum=0, v, w;

	scanf("%d%d%d", &N, &M, &k);
	set=(int *)malloc((N+1)*sizeof(int));
	A=(int *)malloc((N+1)*sizeof(int));

	for(int n=1;n<=N;++n)
	{
		set[n]=n;
		scanf("%d", &A[n]);
	}

	while(M--)
	{
		scanf("%d%d", &v, &w);
		union_set(v,w);
	}

	for(int n=1;n<=N;++n)
		sum+=n==set[n]?A[n]:0;

	if(sum<=k)
		printf("%d", sum);
	else
		printf("Oh no");
	free(A);
	free(set);
	return 0;
}