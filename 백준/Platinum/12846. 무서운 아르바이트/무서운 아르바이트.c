#include<stdio.h>
#include<malloc.h>

long long max=0;
int n, *T=NULL, *tree=NULL;

void init(int node,int start,int end)
{
	if(start==end)
		tree[node]=start;
	else
	{
		init(node<<1,start,(start+end)>>1);
		init(node<<1|1,((start+end)>>1)+1,end);
		tree[node]=T[tree[node<<1]]<T[tree[node<<1|1]]?tree[node<<1]:tree[node<<1|1];
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
			return T[left_child]<T[right_child]?left_child:right_child;
	}
}

void find_max(int left,int right)
{
	if(left>right)
		return;

	int min=get(1,0,n-1,left,right);

	find_max(left,min-1);
	find_max(min+1,right);

	max=max<(long long)T[min]*(right-left+1)?(long long)T[min]*(right-left+1):max;
}

int main(void)
{
	int size=0;

	scanf("%d", &n);
	T=(int *)malloc(n*sizeof(int));

	while((1<<size)<n)
		size++;
	size++;
	tree=(int *)malloc((1<<size)*sizeof(int));

	for(int i=0;i<n;i++)
		scanf("%d", &T[i]);

	init(1,0,n-1);
	find_max(0,n-1);

	printf("%lld\n", max);
	free(tree);
	free(T);
	return 0;
}