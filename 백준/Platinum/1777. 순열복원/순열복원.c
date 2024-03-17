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
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
}

int get(int *tree,int node,int start,int end,int left,int right)
{
	if(left>end || right<start)
		return 0;
	else if(left<=start && end<=right)
		return tree[node];
	else
		return get(tree,node<<1,start,start+end>>1,left,right)+get(tree,node<<1|1,(start+end>>1)+1,end,left,right);
}

void update(int *tree,int node,int start,int end,int index)
{
	if(index<start || index>end)
		return;
	else if(start==end)
	{
		tree[node]=0;
		return;
	}
	else
	{
		update(tree,node<<1,start,start+end>>1,index);
		update(tree,node<<1|1,(start+end>>1)+1,end,index);
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
}

int main(void)
{
	int N, size=0, *inversion_sequence=NULL, *arr=NULL, *tree=NULL;

	scanf("%d", &N);
	while((1<<size)<N)
		++size;
	inversion_sequence=(int *)malloc(N*sizeof(int));
	arr=(int *)malloc(N*sizeof(int));
	tree=(int *)malloc((1<<++size)*sizeof(int));

	init(tree,1,0,N-1);
	for(int n=0;n<N;++n)
		scanf("%d", &inversion_sequence[n]);

	for(int n=N-1;0<=n;--n)
	{
		int left=0, right=N-1, mid, index=0;

		while(left<=right)
		{
			mid=left+right>>1;

			if(inversion_sequence[n]<get(tree,1,0,N-1,mid,N-1))
			{
				index=mid;
				left=mid+1;
			}
			else
				right=mid-1;
		}

		arr[index]=n+1;
		update(tree,1,0,N-1,index);
	}

	for(int n=0;n<N;++n)
		printf("%d ", arr[n]);

	free(inversion_sequence);
	free(arr);
	free(tree);
	return 0;
}