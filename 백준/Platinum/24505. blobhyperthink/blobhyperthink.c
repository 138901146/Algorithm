#include<stdio.h>
#include<malloc.h>

#define MOD 1000000007

int get(int *tree,int node,int start,int end,int left,int right)
{
	if(left>end || right<start)
		return 0;
	else if(left<=start && end<=right)
		return tree[node];
	else
		return (get(tree,node<<1,start,start+end>>1,left,right)+get(tree,node<<1|1,(start+end>>1)+1,end,left,right))%MOD;
}

void update(int *tree,int node,int start,int end,int index,int value)
{
	if(index<start || index>end)
		return;
	else if(start==end)
	{
		tree[node]=(tree[node]+value)%MOD;
		return;
	}
	else
	{
		update(tree,node<<1,start,start+end>>1,index,value);
		update(tree,node<<1|1,(start+end>>1)+1,end,index,value);
		tree[node]=(tree[node<<1]+tree[node<<1|1])%MOD;
	}
}

int main(void)
{
	int N, *A=NULL, size=0, *tree=NULL, **count=NULL, sum=0;

	scanf("%d", &N);
	A=(int *)malloc(N*sizeof(int));
	count=(int **)malloc(12*sizeof(int *));

	for(int i=0;i<12;++i)
		count[i]=(int *)calloc(N,sizeof(int));

	while(1<<size<=N)
		++size;
	tree=(int *)calloc(1<<++size,sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &A[i]);

	update(tree,1,0,N,0,1);
	for(int i=1;i<12;++i)
	{
		for(int j=0;j<N;++j)
		{
			update(tree,1,0,N,A[j],count[i-1][j]);
			count[i][j]=get(tree,1,0,N,0,A[j]-1)%MOD;
		}
		memset(tree,0,(1<<size)*sizeof(int));
	}

	for(int i=0;i<N;++i)
		sum=(sum+count[11][i])%MOD;

	printf("%d", sum);
	for(int i=0;i<12;++i)
		free(count[i]);
	free(count);
	free(A);
	free(tree);
	return 0;
}