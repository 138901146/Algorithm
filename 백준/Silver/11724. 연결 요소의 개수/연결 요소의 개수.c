#include<stdio.h>

int parent[1001];

int find_parent(int v)
{
	if(v==parent[v])
		return v;
	return parent[v]=find_parent(parent[v]);
}

void union_parent(int u,int v)
{
	int x=find_parent(u), y=find_parent(v);

	if(x!=y)
		parent[y]=x;
}

int main(void)
{
	int N, M, u, v, count=0;

	scanf("%d%d", &N, &M);

	for(int n=1;n<=N;++n)
		parent[n]=n;

	while(M--)
	{
		scanf("%d%d", &u, &v);
		union_parent(u,v);
	}

	for(int n=1;n<=N;++n)
		count+=parent[n]==n;

	printf("%d", count);
	return 0;
}