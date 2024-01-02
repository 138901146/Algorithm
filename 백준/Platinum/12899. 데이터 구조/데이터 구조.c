#include<stdio.h>

int tree[4194304]={0};

int get(int node,int start,int end,int X)
{
	if(start>end)
		return 0;
	else if(start==end)
	{
		--tree[node];
		return start;
	}
	else
	{
		int mid=start+end>>1, value=X>tree[node<<1]?get(node<<1|1,mid+1,end,X-tree[node<<1]):get(node<<1,start,mid,X);

		tree[node]=tree[node<<1]+tree[node<<1|1];
		return value;
	}
}

void update(int node,int start,int end,int index)
{
	if(index<start || index>end)
		return;
	else if(start==end)
	{
		++tree[node];
		return;
	}
	else
	{
		update(node<<1,start,start+end>>1,index);
		update(node<<1|1,(start+end>>1)+1,end,index);
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
}

int main(void)
{
	int N, T, X;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d%d", &T, &X);

		if(T==1)
			update(1,1,2000000,X);
		else
			printf("%d\n", get(1,1,2000000,X));
	}

	return 0;
}