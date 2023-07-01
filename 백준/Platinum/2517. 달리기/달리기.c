#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int order, index;
}
player;

int compare(const void *x,const void *y)
{
	return ((player *)x)->order>((player *)y)->order?1:-1;
}

int get(int *tree,int node,int start,int end,int left,int right)
{
	if(left>end || right<start)
		return 0;
	else if(left<=start && end<=right)
		return tree[node];
	else
		return get(tree,node<<1,start,(start+end)>>1,left,right)+get(tree,node<<1|1,((start+end)>>1)+1,end,left,right);
}

void update(int *tree,int node,int start,int end,int index)
{
	if(index<start || index>end)
		return;

	tree[node]++;

	if(start!=end)
	{
		update(tree,node<<1,start,(start+end)>>1,index);
		update(tree,node<<1|1,((start+end)>>1)+1,end,index);
	}
}

int main(void)
{
	int N, *order=NULL, size=1, *tree=NULL;
	player *runner=NULL;

	scanf("%d", &N);
	while((1<<size)<N)
		size++;
	size++;
	runner=(player *)malloc(N*sizeof(player));
	for(int n=0;n<N;n++)
	{
		scanf("%d", &runner[n].order);
		runner[n].index=n;
	}

	qsort((void *)runner,(size_t)N,sizeof(player),compare);

	order=(int *)malloc(N*sizeof(int));
	for(int n=0;n<N;n++)
		order[runner[n].index]=n;

	free(runner);
	tree=(int *)calloc((1<<size),sizeof(int));

	for(int n=0;n<N;n++)
	{
		update(tree,1,0,N-1,order[n]);
		printf("%d\n", n+2-get(tree,1,0,N-1,0,order[n]));
	}

	free(order);
	free(tree);
	return 0;
}