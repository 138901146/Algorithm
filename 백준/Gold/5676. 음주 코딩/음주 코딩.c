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
		tree[node]=tree[node<<1]*tree[node<<1|1];
	}
}

int get(int *tree,int node,int start,int end,int left,int right)
{
	if(left>end || right<start)
		return 1;
	else if(left<=start && end<=right)
		return tree[node];
	else
		return get(tree,node<<1,start,(start+end)>>1,left,right)*get(tree,node<<1|1,((start+end)>>1)+1,end,left,right);
}

void update(int *tree,int node,int start,int end,int index,int value)
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
		tree[node]=tree[node<<1]*tree[node<<1|1];
	}
}

int main(void)
{
	int N, K;

	while(scanf("%d%d", &N, &K)!=EOF)
	{
		int *X=(int *)malloc(N*sizeof(int)), size=0, count=0, *tree=NULL, i, j;
		char operation, *result=(char *)calloc(K+1,sizeof(char));

		while((1<<size)<N)
			size++;
		size++;
		tree=(int *)calloc((1<<size),sizeof(int));

		for(int n=0;n<N;n++)
		{
			scanf("%d", &X[n]);

			if(X[n]>0)
				X[n]=1;
			else if(X[n]<0)
				X[n]=-1;
		}

		init(X,tree,1,0,N-1);

		for(int k=0;k<K;k++)
		{
			getchar();
			scanf("%c%d%d", &operation, &i, &j);

			i--;
			if(operation=='C')
			{
				j=j>0?1:j<0?-1:0;
				if(X[i]!=j)
				{
					X[i]=j;
					update(tree,1,0,N-1,i,j);
				}
			}
			else
			{
				int result=get(tree,1,0,N-1,i,j-1);
				printf("%c", result<0?'-':result>0?'+':'0');
			}
		}

		printf("\n");
		free(result);
		free(X);
		free(tree);
	}

	return 0;
}
