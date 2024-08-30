#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<memory.h>

typedef struct
{
	short bbog, ggog;
}
requirement;

requirement *friend=NULL, *n=NULL, *m=NULL;
short bb=0, gg=0, **adjacent_list=NULL, *adjacent_list_count=NULL, *occupied=NULL;
bool *visited=NULL;

bool dfs(short current)
{
	for(short i=0;i<adjacent_list_count[current];++i)
	{
		short next=adjacent_list[current][i];

		if(!visited[next])
		{
			visited[next]=true;

			if(occupied[next]==-1 || dfs(occupied[next]))
			{
				occupied[next]=current;
				return true;
			}
		}
	}

	return false;
}

int main(void)
{
	short N, M, k, ni, mi, candy=0;
	bool *is_m=NULL;

	scanf("%d%d%d", &N, &M, &k);
	friend=(requirement *)malloc(k*sizeof(requirement));
	is_m=(bool *)malloc(k*sizeof(bool));

	for(short i=0;i<k;++i)
	{
		scanf("%d%d%d", &friend[i].bbog, &friend[i].ggog, &is_m[i]);

		if(is_m[i])
			++gg;
		else
			++bb;
	}

	n=(requirement *)malloc(bb*sizeof(requirement));
	m=(requirement *)malloc(gg*sizeof(requirement));
	bb=gg=0;

	while(k--)
		if(is_m[k])
			m[gg++]=friend[k];
		else
			n[bb++]=friend[k];

	free(friend);
	free(is_m);

	adjacent_list=(short **)malloc(bb*sizeof(short *));
	adjacent_list_count=(short *)calloc(bb,sizeof(short));

	for(short i=0;i<bb;++i)
		for(short j=0;j<gg;++j)
			adjacent_list_count[i]+=n[i].bbog==m[j].bbog || n[i].ggog==n[j].ggog;

	for(short i=0;i<bb;++i)
	{
		adjacent_list[i]=(short *)malloc(adjacent_list_count[i]*sizeof(short));
		adjacent_list_count[i]=0;
	}

	for(short i=0;i<bb;++i)
		for(short j=0;j<gg;++j)
			if(n[i].bbog==m[j].bbog || n[i].ggog==m[j].ggog)
				adjacent_list[i][adjacent_list_count[i]++]=j;

	occupied=(short *)malloc(gg*sizeof(short));
	visited=(bool *)malloc(gg*sizeof(bool));

	for(short i=0;i<gg;++i)
		occupied[i]=-1;

	for(short i=0;i<bb;++i)
	{
		memset(visited,0,gg);
		candy+=dfs(i);
	}

	printf("%d", candy);
	for(short i=0;i<bb;++i)
		free(adjacent_list[i]);
	free(adjacent_list);
	free(adjacent_list_count);
	free(n);
	free(m);
	free(occupied);
	free(visited);
	return 0;
}