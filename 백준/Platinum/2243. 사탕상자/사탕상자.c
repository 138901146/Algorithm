#include<stdio.h>
#include<malloc.h>

int get(int *tree,int node,int start,int end,int left,int right)
{
	if(left>end || right<start)
		return 0;
	else if(left<=start && end<=right)
		return tree[node];
	else
		return get(tree,node<<1,start,(start+end)>>1,left,right)+get(tree,node<<1|1,((start+end)>>1)+1,end,left,right);
}

void update(int *tree,int node,int start,int end,int index,int value)
{
	if(index<start || index>end)
		return;
	else if(start==end)
		tree[node]=value;
	else
	{
		update(tree,node<<1,start,(start+end)>>1,index,value);
		update(tree,node<<1|1,((start+end)>>1)+1,end,index,value);
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
}

int find_flavor(int *tree,int B)
{
	int left=1, right=1000000, mid, order, sum;

	while(left<=right)
	{
		mid=(left+right)>>1;

		sum=get(tree,1,1,1000000,1,mid);

		if(sum<B)
			left=mid+1;
		else
		{
			order=mid;
			right=mid-1;
		}
	}

	return order;
}

int main(void)
{
	int n, *candy=calloc(1000001,sizeof(int)), *tree=calloc(2097152,sizeof(int)), A, B, C;

	scanf("%d", &n);

	for(int i=0;i<n;i++)
	{
		scanf("%d%d", &A, &B);

		if(A==1)
		{
			C=find_flavor(tree,B);
			update(tree,1,1,1000000,C,--candy[C]);
			printf("%d\n", C);
		}
		else
		{
			scanf("%d", &C);
			candy[B]+=C;
			update(tree,1,1,1000000,B,candy[B]);
		}
	}

	free(tree);
	free(candy);
	return 0;
}