#include<stdio.h>
#include<malloc.h>

void init(long long *arr,long long *tree,int node,int start,int end)
{
	if(start==end)
		tree[node]=arr[start];
	else
	{
		init(arr,tree,node<<1,start,start+end>>1);
		init(arr,tree,node<<1|1,(start+end>>1)+1,end);
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
}

void update_lazy(long long *tree,long long *lazy,int node,int start,int end)
{
	if(lazy[node])
	{
		tree[node]+=(end-start+1)*lazy[node];
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

	return get(tree,lazy,node<<1,start,start+end>>1,left,right)+get(tree,lazy,node<<1|1,(start+end>>1)+1,end,left,right);
}

void update_range(long long *tree,long long *lazy,int node,int start,int end,int left,int right,long long diff)
{
	update_lazy(tree,lazy,node,start,end);

	if(left>end || right<start)
		return;
	if(left<=start && end<=right)
	{
		tree[node]+=(end-start+1)*diff;
		if(start!=end)
		{
			lazy[node<<1]+=diff;
			lazy[node<<1|1]+=diff;
		}

		return;
	}

	update_range(tree,lazy,node<<1,start,start+end>>1,left,right,diff);
	update_range(tree,lazy,node<<1|1,(start+end>>1)+1,end,left,right,diff);
	tree[node]=tree[node<<1]+tree[node<<1|1];
}

int main(void)
{
	int N, M, *area=NULL, size=0, a, b, operation, x, y;
	long long *acorn=NULL, *tree=NULL, *lazy=NULL, z;

	scanf("%d%d", &N, &M);

	while((1<<size)<M)
		++size;
	size=1<<++size;
	area=(int *)malloc((N+1)*sizeof(int));
	acorn=(long long *)malloc(M*sizeof(long long));
	tree=(long long *)calloc(size,sizeof(long long));

	for(int m=0;m<M;++m)
	{
		scanf("%d%d%lld", &a, &b, &acorn[m]);
		for(int i=a;i<=b;++i)
			area[i]=m;
	}

	init(acorn,tree,1,0,M-1);

	free(acorn);
	lazy=(long long *)calloc(size,sizeof(long long));

	scanf("%d%d%d", &operation, &x, &y);
	while(operation)
	{
		if(operation==1)
			printf("%lld\n", y<x?get(tree,lazy,1,0,M-1,area[x],M-1)+get(tree,lazy,1,0,M-1,0,area[y]):get(tree,lazy,1,0,M-1,area[x],area[y]));
		else
		{
			scanf("%lld", &z);

			if(y<x)
			{
				update_range(tree,lazy,1,0,M-1,area[x],M-1,z);
				update_range(tree,lazy,1,0,M-1,0,area[y],z);
			}
			else
				update_range(tree,lazy,1,0,M-1,area[x],area[y],z);
		}

		scanf("%d%d%d", &operation, &x, &y);
	}

	free(tree);
	free(lazy);
	free(area);
	return 0;
}