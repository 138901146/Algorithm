#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int value, index;
}
sequence;

int compare(const void *x,const void *y)
{
	return ((sequence *)x)->value<((sequence *)y)->value || ((sequence *)x)->value==((sequence *)y)->value&&((sequence *)x)->index<((sequence *)y)->index?-1:1;
}

void init(int *tree,int node,int start,int end)
{
	if(start==end)
		tree[node]=1;
	else
	{
		init(tree,node<<1,start,(start+end)>>1);
		init(tree,node<<1|1,((start+end)>>1)+1,end);
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
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
	else if(start==end)
	{
		tree[node]=0;
		return;
	}
	else
	{
		update(tree,node<<1,start,(start+end)>>1,index);
		update(tree,node<<1|1,((start+end)>>1)+1,end,index);
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
}

int main(void)
{
	int n, size=0, *tree=NULL;
	long long count=0;
	sequence *a=NULL;

	scanf("%d", &n);
	while((1<<size)<n)
		++size;
	++size;

	a=(sequence *)malloc(n*sizeof(sequence));
	tree=(int *)calloc(1<<size,sizeof(int));

	for(int i=0;i<n;++i)
	{
		scanf("%d", &a[i].value);
		a[i].index=i;
	}

	qsort((void *)a,(size_t)n,sizeof(sequence),compare);
	init(tree,1,0,n-1);

	for(int i=0;i<n;++i)
	{
		count+=get(tree,1,0,n-1,0,a[i].index)-1;
		update(tree,1,0,n-1,a[i].index);
	}

	printf("%lld", count);
	free(a);
	free(tree);
	return 0;
}