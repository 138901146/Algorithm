#include<stdio.h>
#include<malloc.h>

long long max=0;
int N, *H=NULL, *tree=NULL;

void init(int node,int start,int end)
{
	if(start==end)
		tree[node]=start;
	else
	{
		init(node<<1,start,(start+end)>>1);
		init(node<<1|1,((start+end)>>1)+1,end);
		tree[node]=H[tree[node<<1]]<H[tree[node<<1|1]]?tree[node<<1]:tree[node<<1|1];
	}
}

int get(int node,int start,int end,int left,int right)
{
	if(left>end || right<start)
		return 1000000;
	else if(left<=start && end<=right)
		return tree[node];
	else
	{
		int left_child=get(node<<1,start,(start+end)>>1,left,right), right_child=get(node<<1|1,((start+end)>>1)+1,end,left,right);

		if(left_child==1000000)
			return right_child;
		else if(right_child==1000000)
			return left_child;
		else
			return H[left_child]<H[right_child]?left_child:right_child;
	}
}

void find_max(int left,int right)
{
	if(left>right)
		return;

	int min=get(1,0,N-1,left,right);

	max=max<(long long)H[min]*(right-left+1)?(long long)H[min]*(right-left+1):max;

	find_max(left,min-1);
	find_max(min+1,right);
}

int main(void)
{
	int size=0;

	scanf("%d", &N);
	H=(int *)malloc(N*sizeof(int));

	while((1<<size)<N)
		size++;
	size++;
	tree=(int *)malloc((1<<size)*sizeof(int));

	for(int i=0;i<N;i++)
		scanf("%d", &H[i]);

	init(1,0,N-1);
	find_max(0,N-1);

	printf("%lld\n", max);
	free(tree);
	free(H);
	return 0;
}