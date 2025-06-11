#include<stdio.h>
#include<malloc.h>

int *parent=NULL;

int find_parent(int x)
{
	if(parent[x]==x)
		return x;

	return parent[x]=find_parent(parent[x]);
}

void union_parent(int x,int y)
{
	int parent_x=find_parent(x), parent_y=find_parent(y);

	if(parent_x!=parent_y)
		parent[parent_x]=parent_y;
}

int main(void)
{
	int N, M, u, v, count=0;

	scanf("%d%d", &N, &M);
	parent=(int *)malloc((N+1)*sizeof(int));

	for(int n=1;n<=N;++n)
		parent[n]=n;

	while(M--)
	{
		scanf("%d%d", &u, &v);

		if(find_parent(u)==find_parent(v))
			++count;
		else
			union_parent(u,v);
	}

	for(int n=1;n<=N;++n)
		count+=parent[n]==n;

	printf("%d", count-1);
	free(parent);
	return 0;
}