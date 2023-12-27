#include<stdio.h>
#include<malloc.h>

void update_lazy(int *tree,int *lazy,int node,int start,int end)
{
	if(lazy[node]!=0)
	{
		tree[node]+=(end-start+1)*lazy[node];
		if(start!=end)
		{
			lazy[node<<1]+=lazy[node];
			lazy[node<<1|1]+=lazy[node];
		}
		lazy[node]=0;
	}
}

int get(int *tree,int *lazy,int node,int start,int end,int index)
{
	update_lazy(tree,lazy,node,start,end);

	if(index>end || index<start)
		return 0;
	if(index<=start && end<=index)
		return tree[node];

	return get(tree,lazy,node<<1,start,start+end>>1,index)+get(tree,lazy,node<<1|1,(start+end>>1)+1,end,index);
}

void update_range(int *tree,int *lazy,int node,int start,int end,int left,int right,int diff)
{
	update_lazy(tree,lazy,node,start,end);

	if(left>end || right<start)
		return;
	if(left<=start && end<=right)
	{
		tree[node]+=(end-start+1)*diff;
		if(start!=end)
		{
			lazy[node<<1]+=diff;
			lazy[node<<1|1]+=diff;
		}

		return;
	}

	update_range(tree,lazy,node<<1,start,start+end>>1,left,right,diff);
	update_range(tree,lazy,node<<1|1,(start+end>>1)+1,end,left,right,diff);
	tree[node]=tree[node<<1]+tree[node<<1|1];
}


int main(void)
{
	int N, L, R, *tree=NULL, *lazy=NULL, left_value, right_value;

	scanf("%d", &N);
	tree=(int *)calloc(262144,sizeof(int));
	lazy=(int *)calloc(262144,sizeof(int));

	while(N--)
	{
		scanf("%d%d", &L, &R);

		left_value=get(tree,lazy,1,1,100000,L);
		right_value=get(tree,lazy,1,1,100000,R);
		printf("%d\n", left_value+right_value);

		if(left_value)
			update_range(tree,lazy,1,1,100000,L,L,-left_value);
		if(right_value)
			update_range(tree,lazy,1,1,100000,R,R,-right_value);
		if(R-L>1)
			update_range(tree,lazy,1,1,100000,L+1,R-1,1);
	}

	free(tree);
	free(lazy);
	return 0;
}