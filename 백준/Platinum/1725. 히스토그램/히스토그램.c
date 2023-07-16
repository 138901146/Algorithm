#include<stdio.h>
#include<malloc.h>

long long max=0, *tree=NULL;
int N, *h=NULL;

void init(int node,int start,int end)
{
	if(start==end)
		tree[node]=(long long)start<<30|h[start];
	else
	{
		init(node<<1,start,(start+end)>>1);
		init(node<<1|1,((start+end)>>1)+1,end);
		tree[node]=(tree[node<<1]&1073741823)<(tree[node<<1|1]&1073741823)?tree[node<<1]:tree[node<<1|1];
	}
}

long long get(int node,int start,int end,int left,int right)
{
	if(left>end || right<start)
		return 1073741823;
	else if(left<=start && end<=right)
		return tree[node];
	else
	{
		long long left_child=get(node<<1,start,(start+end)>>1,left,right), right_child=get(node<<1|1,((start+end)>>1)+1,end,left,right);

		if(left_child==1073741823)
			return right_child;
		else if(right_child==1073741823)
			return left_child;
		else
			return (left_child&1073741823)<(right_child&1073741823)?left_child:right_child;
	}
}

void find_max(int left,int right)
{
	if(left>right)
		return;

	long long min=get(1,0,N-1,left,right);

	find_max(left,(min>>30)-1);
	find_max((min>>30)+1,right);

	max=max<(min&1073741823)*(right-left+1)?(min&1073741823)*(right-left+1):max;
}

int main(void)
{
	int size=0;

	scanf("%d", &N);
	h=(int *)malloc(N*sizeof(int));

	while((1<<size)<N)
		size++;
	size++;
	tree=(long long *)malloc((1<<size)*sizeof(long long));

	for(int i=0;i<N;i++)
		scanf("%d", &h[i]);

	init(1,0,N-1);
	find_max(0,N-1);

	printf("%lld\n", max);
	free(tree);
	free(h);
	return 0;
}