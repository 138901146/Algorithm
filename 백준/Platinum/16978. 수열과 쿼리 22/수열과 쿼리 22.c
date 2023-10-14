#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int index, i, j, k;
}
print_structure;

typedef struct
{
	int i, v;
}
modify_structure;

int compare(const void *x,const void *y)
{
	return ((print_structure *)x)->k<((print_structure *)y)->k?-1:1;
}

void init(int *arr,long long *tree,int node,int start,int end)
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
	int N, *A=NULL, M, size=0, operation, modify_count=0, print_count=0, modify_done=0, print_done=0;
	long long *tree=NULL, *answer=NULL;
	modify_structure *modify=NULL;
	print_structure *print=NULL;

	scanf("%d", &N);
	while((1<<size)<N)
		++size;
	++size;

	A=(int *)malloc(N*sizeof(int));
	tree=(long long *)calloc((1<<size),sizeof(long long));

	for(int i=0;i<N;++i)
		scanf("%d", &A[i]);

	init(A,tree,1,0,N-1);
	free(A);

	scanf("%d", &M);

	modify=(modify_structure *)malloc(M*sizeof(modify_structure));
	print=(print_structure *)malloc(M*sizeof(print_structure));

	while(M--)
	{
		scanf("%d", &operation);

		if(operation==1)
		{
			scanf("%d%d", &modify[modify_count].i, &modify[modify_count].v);
			++modify_count;
		}
		else
		{
			scanf("%d%d%d", &print[print_count].k, &print[print_count].i, &print[print_count].j);
			print[print_count].index=print_count;
			++print_count;
		}
	}

	answer=(long long *)malloc(print_count*sizeof(long long));
	qsort((void *)print,(size_t)print_count,sizeof(print_structure),compare);

	while(print_done<=print_count)
	{
		while(print_done<=print_count && print[print_done].k<modify_done)
			++print_done;

		while(print_done<=print_count && print[print_done].k==modify_done)
		{
			answer[print[print_done].index]=get(tree,1,0,N-1,print[print_done].i-1,print[print_done].j-1);
			++print_done;
		}

		update(tree,1,0,N-1,modify[modify_done].i-1,modify[modify_done].v);
		++modify_done;
	}

	for(int i=0;i<print_count;++i)
		printf("%lld\n", answer[i]);

	free(print);
	free(modify);
	free(tree);
	free(answer);
	return 0;
}