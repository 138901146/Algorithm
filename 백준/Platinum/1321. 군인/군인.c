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
		return get(tree,node<<1,start,(start+end)>>1,left,right)+get(tree,node<<1|1,((start+end)>>1)+1,end,left,right);
}

void update(int *tree,int node,int start,int end,int index,int diff)
{
	if(index<start || index>end)
		return;
	else if(start==end)
	{
		tree[node]+=diff;
		return;
	}
	else
	{
		update(tree,node<<1,start,(start+end)>>1,index,diff);
		update(tree,node<<1|1,((start+end)>>1)+1,end,index,diff);
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
}

int main(void)
{
	int N, *army=NULL, *tree=NULL, M, size=0, operation, a, b;

	scanf("%d", &N);
	while((1<<size)<N)
		size++;
	size++;
	army=(int *)malloc(N*sizeof(int));
	tree=(int *)calloc((1<<size),sizeof(int));

	for(int i=0;i<N;i++)
		scanf("%d", &army[i]);

	init(army,tree,1,0,N-1);
	free(army);

	scanf("%d", &M);
	for(int m=0;m<M;m++)
	{
		scanf("%d", &operation);

		if(operation==1)
		{
			scanf("%d%d", &a, &b);
			update(tree,1,0,N-1,a-1,b);
		}
		else
		{
			int left=0, right=N-1, mid, ans;

			scanf("%d", &a);

			while(left<=right)
			{
				mid=(left+right)>>1;
				if(get(tree,1,0,N-1,0,mid)<a)
					left=mid+1;
				else
				{
					ans=mid;
					right=mid-1;
				}
			}

			printf("%d\n", ans+1);
		}
	}

	free(tree);
	return 0;
}