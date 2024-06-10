#include<stdio.h>
#include<malloc.h>

void init(int *tree,int node,int start,int end)
{
	if(start==end)
		tree[node]=1;
	else
	{
		init(tree,node<<1,start,start+end>>1);
		init(tree,node<<1|1,(start+end>>1)+1,end);
		tree[node]=1;
	}
}

void update_lazy(int *tree,int *lazy,int node,int start,int end)
{
	if(lazy[node])
	{
		tree[node]=lazy[node];
		if(start!=end)
			lazy[node<<1]=lazy[node<<1|1]=lazy[node];
		lazy[node]=0;
	}
}

int get(int *tree,int *lazy,int node,int start,int end,int left,int right)
{
	update_lazy(tree,lazy,node,start,end);

	if(left>end || right<start)
		return 0;
	if(left<=start && end<=right)
		return tree[node];

	return get(tree,lazy,node<<1,start,start+end>>1,left,right)|get(tree,lazy,node<<1|1,(start+end>>1)+1,end,left,right);
}

void update_range(int *tree,int *lazy,int node,int start,int end,int left,int right,int z)
{
	update_lazy(tree,lazy,node,start,end);

	if(left>end || right<start)
		return;
	if(left<=start && end<=right)
	{
		tree[node]=z;
		if(start!=end)
			lazy[node<<1]=lazy[node<<1|1]=z;

		return;
	}

	update_range(tree,lazy,node<<1,start,start+end>>1,left,right,z);
	update_range(tree,lazy,node<<1|1,(start+end>>1)+1,end,left,right,z);
	tree[node]=tree[node<<1]|tree[node<<1|1];
}

int main(void)
{
	int N, T, Q, x, y, z, *tree=NULL, *lazy=NULL, size=0;
	char operation;

	scanf("%d%d%d", &N, &T, &Q);
	while((1<<size)<N)
		++size;
	size=1<<++size;
	tree=(int *)calloc(size,sizeof(int));
	lazy=(int *)calloc(size,sizeof(int));

	init(tree,1,0,N-1);

	while(Q--)
	{
		getchar();
		scanf("%c%d%d", &operation, &x, &y);

		--x;
		--y;

		if(x>y)
		{
			int temp=x;
			x=y;
			y=temp;
		}

		if(operation=='Q')
		{
			int value=get(tree,lazy,1,0,N-1,x,y), count=0;

			for(int i=0;i<T;++i)
				count+=(1<<i&value)!=0;

			printf("%d\n", count);
		}
		else
		{
			scanf("%d", &z);
			update_range(tree,lazy,1,0,N-1,x,y,1<<--z);
		}
	}

	free(tree);
	free(lazy);
	return 0;
}