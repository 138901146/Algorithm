#include<stdio.h>

int tree[524288], location[100001];

void init(int node,int start,int end,int n)
{
	if(start==end)
		tree[node]=1<=start&&end<=n;
	else
	{
		init(node<<1,start,start+end>>1,n);
		init(node<<1|1,(start+end>>1)+1,end,n);
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
}

int get(int node,int start,int end,int left,int right)
{
	if(left>end || right<start)
		return 0;
	else if(left<=start && end<=right)
		return tree[node];
	else
		return get(node<<1,start,start+end>>1,left,right)+get(node<<1|1,(start+end>>1)+1,end,left,right);
}

void update(int node,int start,int end,int index,int value)
{
	if(index<start || index>end)
		return;
	else if(start==end)
	{
		tree[node]=value;
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
	int T;

	scanf("%d", &T);

	while(T--)
	{
		int n, m, end, movie;

		scanf("%d%d", &n, &m);

		for(int i=n;i;--i)
			location[i]=n-i+1;
		end=n;

		init(1,1,n+m,n);
		n+=m;

		for(int i=m;i;--i)
		{
			scanf("%d", &movie);

			printf("%d ", get(1,1,n,location[movie]+1,end));

			update(1,1,n,location[movie],0);
			update(1,1,n,++end,1);
			location[movie]=end;
		}
		printf("\n");
	}

	return 0;
}