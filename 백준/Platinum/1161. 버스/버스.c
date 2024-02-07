#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int S, E, M;
}
group;

int compare(const void *x,const void *y)
{
	return ((group *)x)->E<((group *)y)->E?-1:((group *)x)->E>((group *)y)->E?1:((group *)x)->S<((group *)y)->S?-1:1;
}

void update_lazy(long long *tree,long long *lazy,int node,int start,int end)
{
	if(lazy[node]!=0)
	{
		tree[node]+=lazy[node];
		if(start!=end)
		{
			lazy[node<<1]+=lazy[node];
			lazy[node<<1|1]+=lazy[node];
		}
		lazy[node]=0;
	}
}

long long get(long long *tree,long long *lazy,int node,int start,int end,int left,int right)
{
	update_lazy(tree,lazy,node,start,end);

	if(left>end || right<start)
		return 0;
	if(left<=start && end<=right)
		return tree[node];

	long long left_child=get(tree,lazy,node<<1,start,start+end>>1,left,right), right_child=get(tree,lazy,node<<1|1,(start+end>>1)+1,end,left,right);

	return left_child<right_child?right_child:left_child;
}

void update_range(long long *tree,long long *lazy,int node,int start,int end,int left,int right,long long diff)
{
	update_lazy(tree,lazy,node,start,end);

	if(left>end || right<start)
		return;
	if(left<=start && end<=right)
	{
		tree[node]+=diff;
		if(start!=end)
		{
			lazy[node<<1]+=diff;
			lazy[node<<1|1]+=diff;
		}

		return;
	}

	update_range(tree,lazy,node<<1,start,start+end>>1,left,right,diff);
	update_range(tree,lazy,node<<1|1,(start+end>>1)+1,end,left,right,diff);
	tree[node]=tree[node<<1]<tree[node<<1|1]?tree[node<<1|1]:tree[node<<1];
}

int main(void)
{
	int K, N, C, size=0;
	group *passenger=NULL;
	long long *tree=NULL, *lazy=NULL, total=0;

	scanf("%d%d%d", &K, &N, &C);
	passenger=(group *)malloc(K*sizeof(group));

	for(int k=0;k<K;++k)
		scanf("%d%d%d", &passenger[k].S, &passenger[k].E, &passenger[k].M);
	qsort((void *)passenger,(size_t)K,sizeof(group),compare);

	while((1<<size)<=N)
		++size;
	size=1<<++size;

	tree=(long long *)calloc(size,sizeof(long long));
	lazy=(long long *)calloc(size,sizeof(long long));

	for(int k=0;k<K;++k)
	{
		long long current=get(tree,lazy,1,1,N,passenger[k].S,passenger[k].E-1), board=current+passenger[k].M<=C?passenger[k].M:C-current;
		update_range(tree,lazy,1,1,N,passenger[k].S,passenger[k].E-1,board);
		total+=board;
	}

	printf("%lld", total);
	free(tree);
	free(lazy);
	free(passenger);
	return 0;
}