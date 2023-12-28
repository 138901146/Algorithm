#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int size, *list;
}
merge_sort_tree;

void init(int *arr,merge_sort_tree *tree,int node,int start,int end)
{
	if(start==end)
	{
		tree[node].size=1;
		tree[node].list=(int *)malloc(sizeof(int));
		tree[node].list[0]=arr[start];
	}
	else
	{
		int left=node<<1, right=left|1, left_size=0, right_size=0;

		init(arr,tree,left,start,start+end>>1);
		init(arr,tree,right,(start+end>>1)+1,end);
		tree[node].size=tree[left].size+tree[right].size;
		tree[node].list=(int *)malloc(tree[node].size*sizeof(int));

		for(int i=0;i<tree[node].size;++i)
			if(left_size==tree[left].size)
				tree[node].list[i]=tree[right].list[right_size++];
			else if(right_size==tree[right].size)
				tree[node].list[i]=tree[left].list[left_size++];
			else if(tree[left].list[left_size]<tree[right].list[right_size])
				tree[node].list[i]=tree[left].list[left_size++];
			else
				tree[node].list[i]=tree[right].list[right_size++];
	}
}

int get(merge_sort_tree *tree,int node,int start,int end,int left,int right,int k)
{
	if(left>end || right<start)
		return 0;
	else if(left<=start && end<=right)
	{
		int low=0, high=end-start+1, mid, ans=end-start+1;

		while(low<=high)
		{
			mid=low+high>>1;

			if(tree[node].list[mid]<=k)
				low=mid+1;
			else
			{
				ans=mid;
				high=mid-1;
			}
		}

		return end-start+1-ans;
	}
	else
		return get(tree,node<<1,start,start+end>>1,left,right,k)+get(tree,node<<1|1,(start+end>>1)+1,end,left,right,k);
}

void free_tree(merge_sort_tree *tree,int node,int start,int end)
{
	if(start!=end)
	{
		free_tree(tree,node<<1,start,start+end>>1);
		free_tree(tree,node<<1|1,(start+end>>1)+1,end);
	}
	free(tree[node].list);
}

int main(void)
{
	int N, M, i, j, k, *A=NULL, size=0, last_ans=0;
	merge_sort_tree *tree=NULL;

	scanf("%d", &N);
	while((1<<size)<=N)
		++size;
	A=(int *)malloc((N+1)*sizeof(int));
	tree=(merge_sort_tree *)malloc((1<<++size)*sizeof(merge_sort_tree));

	for(i=1;i<=N;++i)
		scanf("%d", &A[i]);

	init(A,tree,1,1,N);

	scanf("%d", &M);
	while(M--)
	{
		scanf("%d%d%d", &i, &j, &k);
		printf("%d\n", get(tree,1,1,N,i,j,k));
	}

	free(A);
	free_tree(tree,1,1,N);
	free(tree);
	return 0;
}