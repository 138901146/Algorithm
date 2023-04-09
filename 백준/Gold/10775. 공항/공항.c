#include<stdio.h>
#include<stdlib.h>

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
	int G, P, *g=NULL, count=0;

	scanf("%d", &G);
	scanf("%d", &P);
	g=(int *)malloc(P*sizeof(int));
	parent=(int *)malloc((G+1)*sizeof(int));
	for(int i=0;i<=G;i++)
		parent[i]=i;
	for(int i=0;i<P;i++)
		scanf("%d", &g[i]);

	for(int i=0;i<P;i++)
	{
		int p=find_parent(g[i]);

		if(p!=0)
		{
			union_set(p,p-1);
			count++;
		}
		else
			break;
	}

	printf("%d\n", count);
	free(g);
	free(parent);
	return 0;
}