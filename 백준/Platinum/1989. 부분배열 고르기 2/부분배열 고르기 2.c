#include<stdio.h>
#include<malloc.h>

long long max=0, *sum=NULL;
int N, *A=NULL, *tree=NULL, max_left=0, max_right;

void init(int node,int start,int end)
{
	if(start==end)
		tree[node]=start;
	else
	{
		init(node<<1,start,(start+end)>>1);
		init(node<<1|1,((start+end)>>1)+1,end);
		tree[node]=A[tree[node<<1]]<A[tree[node<<1|1]]?tree[node<<1]:tree[node<<1|1];
	}
}

int get(int node,int start,int end,int left,int right)
{
	if(left>end || right<start)
		return 100000000;
	else if(left<=start && end<=right)
		return tree[node];
	else
	{
		int left_child=get(node<<1,start,(start+end)>>1,left,right), right_child=get(node<<1|1,((start+end)>>1)+1,end,left,right);

		if(left_child==100000000)
			return right_child;
		else if(right_child==100000000)
			return left_child;
		else
			return A[left_child]<A[right_child]?left_child:right_child;
	}
}

void find_max(int left,int right)
{
	if(left>right)
		return;

	int min=get(1,0,N-1,left,right);

	find_max(left,min-1);
	find_max(min+1,right);

	if(max<(long long)A[min]*(sum[right+1]-sum[left]))
	{
		max=(long long)A[min]*(sum[right+1]-sum[left]);
		max_left=left;
		max_right=right;
	}
}

int main(void)
{
	int size=0;

	scanf("%d", &N);
	A=(int *)malloc(N*sizeof(int));
	sum=(long long *)malloc((N+1)*sizeof(long long));
	sum[0]=0;
	max_right=N-1;

	while((1<<size)<N)
		size++;
	size++;
	tree=(int *)malloc((1<<size)*sizeof(int));

	for(int i=0;i<N;i++)
	{
		scanf("%d", &A[i]);
		sum[i+1]=sum[i]+A[i];
	}

	init(1,0,N-1);
	find_max(0,N-1);

	printf("%lld\n%d %d", max, max_left+1, max_right+1);
	free(tree);
	free(sum);
	free(A);
	return 0;
}