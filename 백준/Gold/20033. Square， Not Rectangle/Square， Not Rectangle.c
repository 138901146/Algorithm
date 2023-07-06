#include<stdio.h>
#include<malloc.h>

void init(int *arr,int *tree,int node,int start,int end)
{
	if(start==end)
		tree[node]=arr[start];
	else
	{
		init(arr,tree,node<<1,start,(start+end)>>1);
		init(arr,tree,node<<1|1,((start+end)>>1)+1,end);
		tree[node]=tree[node<<1]<tree[node<<1|1]?tree[node<<1]:tree[node<<1|1];
	}
}

int get(int *tree,int node,int start,int end,int left,int right)
{
	if(left>end || right<start)
		return 2000000000;
	else if(left<=start && end<=right)
		return tree[node];
	else
	{
		int left_value=get(tree,node<<1,start,(start+end)>>1,left,right), right_value=get(tree,node<<1|1,((start+end)>>1)+1,end,left,right);
		if(left_value==2000000000)
			return right_value;
		else if(right_value==2000000000)
			return left_value;
		return left_value<right_value?left_value:right_value;
	}
}

int main(void)
{
	int N, *H=NULL, *tree=NULL, size=1, ans=0;

	scanf("%d", &N);
	while((1<<size)<N)
		size++;
	size++;
	H=(int *)malloc(N*sizeof(int));
	tree=(int *)malloc((1<<size)*sizeof(int));

	for(int i=0;i<N;i++)
		scanf("%d", &H[i]);

	init(H,tree,1,0,N-1);

	for(int i=0;i<N;i++)
	{
		int left=i, right=N-1, mid, height, max=0;

		while(left<=right)
		{
			mid=(left+right)>>1;

			height=get(tree,1,0,N-1,i,mid);

			if(height>mid-i)
			{
				max=mid-i+1;
				left=mid+1;
			}
			else
				right=mid-1;
		}

		ans=max>ans?max:ans;
	}

	printf("%d\n", ans);
	free(tree);
	free(H);
	return 0;
}