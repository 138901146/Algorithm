#include<stdio.h>
#include<malloc.h>

void init(int *tree,int node,int start,int end,int is_min)
{
	if(start==end)
		tree[node]=start;
	else
	{
		init(tree,node<<1,start,start+end>>1,is_min);
		init(tree,node<<1|1,(start+end>>1)+1,end,is_min);
		tree[node]=is_min^tree[node<<1]<tree[node<<1|1]?tree[node<<1|1]:tree[node<<1];
	}
}

int get(int *tree,int node,int start,int end,int left,int right,int is_min)
{
	if(left>end || right<start)
		return -1;
	else if(left<=start && end<=right)
		return tree[node];

	int left_value=get(tree,node<<1,start,start+end>>1,left,right,is_min), right_value=get(tree,node<<1|1,(start+end>>1)+1,end,left,right,is_min);

	if(left_value==-1)
		return right_value;
	else if(right_value==-1)
		return left_value;

	return is_min^left_value<right_value?right_value:left_value;
}

void update(int *tree,int node,int start,int end,int index,int value,int is_min)
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
		update(tree,node<<1,start,start+end>>1,index,value,is_min);
		update(tree,node<<1|1,(start+end>>1)+1,end,index,value,is_min);
		tree[node]=is_min^tree[node<<1]<tree[node<<1|1]?tree[node<<1|1]:tree[node<<1];
	}
}

int main(void)
{
	int T;

	scanf("%d", &T);

	while(T--)
	{
		int N, K, Q, A, B, size=0, *min=NULL, *max=NULL;

		scanf("%d%d", &N, &K);
		while((1<<size)<N)
			++size;
		size=1<<++size;
		min=(int *)malloc(size*sizeof(int));
		max=(int *)malloc(size*sizeof(int));

		init(min,1,0,N-1,1);
		init(max,1,0,N-1,0);

		while(K--)
		{
			scanf("%d%d%d", &Q, &A, &B);

			if(Q)
				printf("%s\n", get(min,1,0,N-1,A,B,1)==A && get(max,1,0,N-1,A,B,0)==B ? "YES" : "NO");
			else
			{
				int A_value=get(min,1,0,N-1,A,A,1), B_value=get(min,1,0,N-1,B,B,1);

				update(min,1,0,N-1,A,B_value,1);
				update(min,1,0,N-1,B,A_value,1);
				update(max,1,0,N-1,A,B_value,0);
				update(max,1,0,N-1,B,A_value,0);
			}
		}

		free(min);
		free(max);
	}

	return 0;
}