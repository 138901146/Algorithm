#include<stdio.h>

int N, D[1000001], tree[2097152];
long long max=0;

void init(int node,int start,int end)
{
	if(start==end)
	{
		tree[node]=start;
		return;
	}

	init(node<<1,start,start+end>>1);
	init(node<<1|1,(start+end>>1)+1,end);
	tree[node]=D[tree[node<<1]]<D[tree[node<<1|1]]?tree[node<<1]:tree[node<<1|1];
}

int get(int node,int left,int right,int start,int end)
{
	if(end<left || right<start)
		return 0;
	else if(left<=start && end<=right)
		return tree[node];

	int left_child=get(node<<1,left,right,start,start+end>>1), right_child=get(node<<1|1,left,right,(start+end>>1)+1,end);

	if(!left_child)
		return right_child;
	else if(!right_child)
		return left_child;
	else
		return D[left_child]<D[right_child]?left_child:right_child;
}

void find_max_area(int start,int end)
{
	if(start>end)
		return;

	int min=get(1,start,end,1,N);

	find_max_area(start,min-1);
	find_max_area(min+1,end);

	max=max<(long long)D[min]*(end-start+1)?(long long)D[min]*(end-start+1):max;
}

int main(void)
{
	scanf("%d", &N);

	for(int i=1;i<=N;++i)
		scanf("%d", &D[i]);

	init(1,1,N);
	find_max_area(1,N);

	printf("%lld", max);
	return 0;
}