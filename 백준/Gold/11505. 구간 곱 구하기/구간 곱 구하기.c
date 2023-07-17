#include<stdio.h>
#include<malloc.h>

void init(int *arr,unsigned long long *tree,int node,int start,int end)
{
	if(start==end)
		tree[node]=arr[start];
	else
	{
		init(arr,tree,node<<1,start,(start+end)>>1);
		init(arr,tree,node<<1|1,((start+end)>>1)+1,end);
		tree[node]=(tree[node<<1]*tree[node<<1|1])%1000000007;
	}
}

unsigned long long get(unsigned long long *tree,int node,int start,int end,int left,int right)
{
	if(left>end || right<start)
		return 1;
	else if(left<=start && end<=right)
		return tree[node];
	else
		return (get(tree,node<<1,start,(start+end)>>1,left,right)*get(tree,node<<1|1,((start+end)>>1)+1,end,left,right))%1000000007;
}

void update(unsigned long long *tree,int node,int start,int end,int index,int value)
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
		update(tree,node<<1,start,(start+end)>>1,index,value);
		update(tree,node<<1|1,((start+end)>>1)+1,end,index,value);
		tree[node]=(tree[node<<1]*tree[node<<1|1])%1000000007;
	}
}

int main(void)
{
	int N, M, K, *arr=NULL, operation[3], size=0;
	unsigned long long *tree=NULL;

	scanf("%d%d%d", &N, &M, &K);
	M+=K;
	while((1<<size)<N)
		size++;
	size++;
	arr=(int *)malloc(N*sizeof(int));
	tree=(unsigned long long *)malloc((1<<size)*sizeof(unsigned long long));

	for(int n=0;n<N;n++)
		scanf("%d", &arr[n]);
	init(arr,tree,1,0,N-1);

	for(int m=0;m<M;m++)
	{
		for(int i=0;i<3;i++)
			scanf("%d", &operation[i]);

		if(operation[0]==1)
			update(tree,1,0,N-1,operation[1]-1,operation[2]);
		else
			printf("%llu\n", get(tree,1,0,N-1,operation[1]-1,operation[2]-1));
	}

	free(arr);
	free(tree);
	return 0;
}