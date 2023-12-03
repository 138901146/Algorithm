#include<stdio.h>

int arr[250000];
long long tree[262144]={0};

long long get(int node,int start,int end,int index)
{
	if(start==end)
		return start;
	else if(tree[node<<1]>=index)
		return get(node<<1,start,start+end>>1,index);
	else
		return get(node<<1|1,(start+end>>1)+1,end,index-tree[node<<1]);
}

void update(int node,int start,int end,int index,int value)
{
	if(index<start || index>end)
		return;
	else if(start==end)
	{
		tree[node]+=value;
		return;
	}
	else
	{
		update(node<<1,start,start+end>>1,index,value);
		update(node<<1|1,(start+end>>1)+1,end,index,value);
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
}

int main(void)
{
	int N, M, K, left=0, right=0, mid;
	long long sum=0;

	scanf("%d%d", &N, &K);

	for(int n=0;n<N;++n)
		scanf("%d", &arr[n]);

	while(right<K-1)
		update(1,0,65535,arr[right++],1);

	mid=K+1>>1;
	while(right<N)
	{
		update(1,0,65535,arr[right++],1);
		sum+=get(1,0,65535,mid);
		update(1,0,65535,arr[left++],-1);
	}

	printf("%lld", sum);
	return 0;
}