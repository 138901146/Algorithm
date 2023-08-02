#include<stdio.h>
#include<malloc.h>

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
	int T, B, P, Q, *tree=NULL, size=0, i, j;
	char operation;

	scanf("%d", &T);
	while(T--)
	{
		int size=0;
		scanf("%d%d%d", &B, &P, &Q);
		P+=Q;
		while((1<<size)<B)
			size++;
		size++;
		tree=(int *)calloc((1<<size),sizeof(int));

		while(P--)
		{
			getchar();
			scanf("%c%d%d", &operation, &i, &j);
			if(operation=='P')
				update(tree,1,0,B-1,i-1,j);
			else
				printf("%d\n", get(tree,1,0,B-1,i-1,j-1));
		}

		free(tree);
	}

	return 0;
}