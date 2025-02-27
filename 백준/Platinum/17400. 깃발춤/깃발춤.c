#include<stdio.h>
#include<malloc.h>

long long abs(long long x)
{
	return x<0?-x:x;
}

void init(int *arr,long long *tree,int node,int start,int end)
{
	if(start==end)
		tree[node]=arr[start];
	else
	{
		init(arr,tree,node<<1,start,(start+end)>>1);
		init(arr,tree,node<<1|1,((start+end)>>1)+1,end);
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
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

void update(long long *tree,int node,int start,int end,int index,int diff)
{
	if(index<start || index>end)
		return;
	else if(start==end)
	{
		tree[node]+=diff;
		return;
	}
	else
	{
		update(tree,node<<1,start,start+end>>1,index,diff);
		update(tree,node<<1|1,(start+end>>1)+1,end,index,diff);
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
}

int main(void)
{
	int N, Q, *odd=NULL, *even=NULL, size=0, query[3];
	long long *odd_tree=NULL, *even_tree=NULL;

	scanf("%d%d", &N, &Q);
	odd=(int *)calloc(N+1,sizeof(int));
	even=(int *)calloc(N+1,sizeof(int));

	while(1<<size<=N)
		++size;
	size=1<<++size;
	odd_tree=(long long *)malloc(size*sizeof(long long));
	even_tree=(long long *)malloc(size*sizeof(long long));

	for(int i=1;i<=N;++i)
		scanf("%d", i&1?&odd[i]:&even[i]);

	init(odd,odd_tree,1,1,N);
	init(even,even_tree,1,1,N);

	while(Q--)
	{
		for(int i=0;i<3;++i)
			scanf("%d", &query[i]);

		if(query[0]==1)
			printf("%lld\n", abs(get(odd_tree,1,1,N,query[1],query[2])-get(even_tree,1,1,N,query[1],query[2])));
		else if(query[1]&1)
			update(odd_tree,1,1,N,query[1],query[2]);
		else
			update(even_tree,1,1,N,query[1],query[2]);
	}

	free(odd);
	free(even);
	free(odd_tree);
	free(even_tree);
	return 0;
}