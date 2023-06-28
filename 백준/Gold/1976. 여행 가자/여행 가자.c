#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

int *parent=NULL;

int find_parent(int x)
{
	if(parent[x]==x)
		return x;
	return parent[x]=find_parent(parent[x]);
}

void union_set(int x,int y)
{
	int parent_x=find_parent(x), parent_y=find_parent(y);

	if(parent_x<parent_y)
		parent[y]=find_parent(x);
	else if(parent_x>parent_y)
		parent[x]=find_parent(y);
}

int main(void)
{
	int N, M, base, target, connected;
	bool different=false, **city=NULL;

	scanf("%d", &N);
	city=(bool **)malloc((N+1)*sizeof(bool *));
	parent=(int *)malloc((N+1)*sizeof(int));
	for(int n=1;n<=N;n++)
	{
		city[n]=(bool *)calloc(N+1,sizeof(bool));
		parent[n]=n;
	}

	scanf("%d", &M);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
		{
			scanf("%d", &connected);
			if(connected)
				city[i][j]=city[j][i]=true;
		}

	for(int i=1;i<=N;i++)
		for(int j=i+1;j<=N;j++)
			if(city[i][j])
				for(int k=1;k<=N;k++)
				{
					if(city[i][k])
						city[j][k]=city[k][j]=true;
					if(city[j][k])
						city[i][k]=city[k][i]=true;
				}

	for(int i=1;i<=N;i++)
		for(int j=i+1;j<=N;j++)
			if(city[i][j])
				union_set(i,j);

	scanf("%d", &base);
	for(int m=1;m<M;m++)
	{
		scanf("%d", &target);
		if(find_parent(target)!=find_parent(base))
		{
			different=true;
			break;
		}
	}

	printf("%s\n", different?"NO":"YES");
	for(int n=1;n<=N;n++)
		free(city[n]);
	free(city);
	free(parent);
	return 0;
}