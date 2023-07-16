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

void update(long long *tree,int node,int start,int end,int index,int value)
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
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
}

int main(void)
{
	int N, M, size=0, operation[3];
	long long *tree=NULL;

	scanf("%d%d", &N, &M);
	while((1<<size)<N)
		size++;
	size++;
	tree=(long long *)calloc((1<<size),sizeof(long long));

	for(int m=0;m<M;m++)
	{
		for(int i=0;i<3;i++)
			scanf("%d", &operation[i]);

		if(operation[0])
			update(tree,1,0,N-1,operation[1]-1,operation[2]);
		else
		{
			if(operation[1]>operation[2])
				for(int i=0;i<3;i++)
					operation[i]=operation[(i+1)%3];
			printf("%lld\n", get(tree,1,0,N-1,(int)operation[1]-1,(int)operation[2]-1));
		}
	}

	free(tree);
	return 0;
}