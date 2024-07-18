#include<stdio.h>
#include<malloc.h>

int *parent=NULL;

int find_parent(int x)
{
	if(parent[x]==x)
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
	int G, P, g, count=0;

	scanf("%d", &G);
	scanf("%d", &P);
	parent=(int *)malloc((G+1)*sizeof(int));

	for(int i=0;i<=G;++i)
		parent[i]=i;

	for(int i=0;i<P;++i)
	{
		scanf("%d", &g);
		g=find_parent(g);

		if(g)
		{
			union_set(g,g-1);
			++count;
		}
		else
			break;
	}

	printf("%d", count);
	free(parent);
	return 0;
}