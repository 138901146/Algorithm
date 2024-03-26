#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int east, west;
}
road;

int compare(const void *x,const void *y)
{
	return ((road *)x)->east>((road *)y)->east?1:((road *)x)->east<((road *)y)->east?-1:((road *)x)->west>((road *)y)->west?1:-1;
}

long long get(long long *tree,int node,int start,int end,int left,int right)
{
	if(left>end || right<start)
		return 0;
	else if(left<=start && end<=right)
		return tree[node];
	else
		return get(tree,node<<1,start,start+end>>1,left,right)+get(tree,node<<1|1,(start+end>>1)+1,end,left,right);
}

void update(long long *tree,int node,int start,int end,int index)
{
	if(index<start || index>end)
		return;
	else if(start==end)
	{
		++tree[node];
		return;
	}
	else
	{
		update(tree,node<<1,start,start+end>>1,index);
		update(tree,node<<1|1,(start+end>>1)+1,end,index);
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
}

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int t=1;t<=T;++t)
	{
		int N, M, K, size=0;
		road *highway=NULL;
		long long *tree=NULL, sum=0;

		scanf("%d%d%d", &N, &M, &K);
		while((1<<size)<=M)
			++size;
		tree=(long long *)calloc(1<<++size,sizeof(long long));
		highway=(road *)malloc(K*sizeof(road));

		for(int k=0;k<K;++k)
			scanf("%d%d", &highway[k].east, &highway[k].west);
		qsort((void *)highway,(size_t)K,sizeof(road),compare);

		for(int k=0;k<K;++k)
		{
			sum+=get(tree,1,1,M,highway[k].west+1,M);
			update(tree,1,1,M,highway[k].west);
		}

		printf("Test case %d: %lld\n", t, sum);
		free(highway);
		free(tree);
	}

	return 0;
}