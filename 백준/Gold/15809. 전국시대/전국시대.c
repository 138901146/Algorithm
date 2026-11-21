#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int *A=NULL, *parent=NULL;

int find_parent(int x)
{
	if(parent[x]==x)
		return x;
	return parent[x]=find_parent(parent[x]);
}

void alliance(int x,int y)
{
	int parent_x=find_parent(x), parent_y=find_parent(y);

	A[parent_x]+=A[parent_y];
	parent[parent_y]=parent_x;
}

void war(int x,int y)
{
	int parent_x=find_parent(x), parent_y=find_parent(y);

	if(A[parent_x]==A[parent_y])
		parent[parent_x]=parent[parent_y]=0;
	else if(A[parent_x]<A[parent_y])
	{
		A[parent_y]-=A[parent_x];
		parent[parent_x]=parent_y;
	}
	else
	{
		A[parent_x]-=A[parent_y];
		parent[parent_y]=parent_x;
	}
}

int main(void)
{
	int N, M, O, P, Q, count=0, *left=NULL;

	scanf("%d%d", &N, &M);

	A=(int *)malloc((N+1)*sizeof(int));
	parent=(int *)malloc((N+1)*sizeof(int));

	for(int i=1;i<=N;++i)
		scanf("%d", &A[i]);
	for(int i=1;i<=N;++i)
		parent[i]=i;

	while(M--)
	{
		scanf("%d%d%d", &O, &P, &Q);

		if(O==1)
			alliance(P,Q);
		else
			war(P,Q);
	}

	for(int i=1;i<=N;++i)
		count+=parent[i]==i;

	left=(int *)malloc(count*sizeof(int));
	count=0;
	for(int i=1;i<=N;++i)
		if(parent[i]==i)
			left[count++]=A[i];
	qsort((void *)left,(size_t)count,sizeof(int),compare);

	printf("%d\n", count);
	for(int i=0;i<count;++i)
		printf("%d ", left[i]);
	free(parent);
	free(A);
	free(left);
	return 0;
}