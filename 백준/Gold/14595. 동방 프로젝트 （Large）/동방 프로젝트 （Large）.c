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
	{
		if(parent_y<parent_x)
		{
			int temp=parent_x;
			parent_x=parent_y;
			parent_y=temp;
		}

		parent[parent_y]=parent_x;
	}
}

int main(void)
{
	int N, M, x, y, count=0, min=1234567;

	scanf("%d", &N);

	parent=(int *)malloc((N+1)*sizeof(int));

	for(int i=0;i<=N;++i)
		parent[i]=i;

	scanf("%d", &M);

	while(M--)
	{
		scanf("%d%d", &x, &y);
		union_parent(x,y);
	}

	for(int i=N;i;--i)
	{
		find_parent(i);

		if(parent[i]<=min&&parent[i]==i)
			++count;
		else if(parent[i]<min)
			min=parent[i];
	}

	printf("%d", count);
	free(parent);
	return 0;
}