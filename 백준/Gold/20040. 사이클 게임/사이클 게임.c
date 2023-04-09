#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int *parent=NULL;

int find_parent(int x)
{
	if(x==parent[x])
		return x;
	return parent[x]=find_parent(parent[x]);
}

void union_set(int x,int y)
{
	if(find_parent(x)!=find_parent(y))
		parent[find_parent(x)]=find_parent(y);
}

int main(void)
{
	int n, m, count=1, a, b;
	bool found=false;

	scanf("%d%d", &n, &m);
	parent=(int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
		parent[i]=i;

	for(int i=0;i<m;i++)
	{
		scanf("%d%d", &a, &b);
		if(find_parent(a)!=find_parent(b))
		{
			count++;
			union_set(a,b);
		}
		else
		{
			found=true;
			break;
		}
	}

	printf("%d\n", found?count:0);
	free(parent);
	return 0;
}