#include<stdio.h>
#include<malloc.h>

void init(int *arr,int *tree,int node,int start,int end,int is_min)
{
	if(start==end)
		tree[node]=arr[start];
	else
	{
		init(arr,tree,node<<1,start,(start+end)>>1,is_min);
		init(arr,tree,node<<1|1,((start+end)>>1)+1,end,is_min);
		tree[node]=is_min?tree[node<<1]<tree[node<<1|1]?tree[node<<1]:tree[node<<1|1]:tree[node<<1]<tree[node<<1|1]?tree[node<<1|1]:tree[node<<1];
	}
}

int get(int *tree,int node,int start,int end,int left,int right,int is_min)
{
	if(left>end || right<start)
		return 2000000000;
	else if(left<=start && end<=right)
		return tree[node];
	else
	{
		int left_value=get(tree,node<<1,start,(start+end)>>1,left,right,is_min), right_value=get(tree,node<<1|1,((start+end)>>1)+1,end,left,right,is_min);
		if(left_value==2000000000)
			return right_value;
		else if(right_value==2000000000)
			return left_value;
		return is_min?left_value<right_value?left_value:right_value:left_value<right_value?right_value:left_value;
	}
}

int main(void)
{
	int N, M, a, b, *min=NULL, *max=NULL, *arr=NULL, size=1;

	scanf("%d%d", &N, &M);
	while((1<<size)<N)
		size++;
	size++;
	min=(int *)malloc((1<<size)*sizeof(int));
	max=(int *)malloc((1<<size)*sizeof(int));
	arr=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;n++)
		scanf("%d", &arr[n]);

	init(arr,min,1,0,N-1,1);
	init(arr,max,1,0,N-1,0);
	free(arr);

	for(int m=0;m<M;m++)
	{
		scanf("%d%d", &a, &b);
		a--;
		b--;
		printf("%d %d\n", get(min,1,0,N-1,a,b,1), get(max,1,0,N-1,a,b,0));
	}

	free(min);
	free(max);
	return 0;
}