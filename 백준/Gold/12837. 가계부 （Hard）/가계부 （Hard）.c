#include<stdio.h>
#include<malloc.h>

long long get(long long *tree,int node,int start,int end,int left,int right)
{
	if(left>end || right<start)
		return 0;
	else if(left<=start && end<=right)
		return tree[node];
	else
		return get(tree,node<<1,start,(start+end)>>1,left,right)+get(tree,node<<1|1,((start+end)>>1)+1,end,left,right);
}

void update(long long *tree,int node,int start,int end,int index,long long value)
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

int main(void)
{
	int N, Q, size=0;
	long long *arr=NULL, *tree=NULL, operation[3];

	scanf("%d%d", &N, &Q);
	while((1<<size)<N)
		size++;
	size++;
	arr=(long long *)calloc(N,sizeof(long long));
	tree=(long long *)calloc((1<<size),sizeof(long long));

	for(int q=0;q<Q;q++)
	{
		for(int i=0;i<3;i++)
			scanf("%lld", &operation[i]);

		operation[1]--;
		if(operation[0]==1)
		{
			operation[2]+=arr[operation[1]];
			arr[operation[1]]=operation[2];
			update(tree,1,0,N-1,operation[1],operation[2]);
		}
		else
			printf("%lld\n", get(tree,1,0,N-1,operation[1],operation[2]-1));
	}

	free(arr);
	free(tree);
	return 0;
}