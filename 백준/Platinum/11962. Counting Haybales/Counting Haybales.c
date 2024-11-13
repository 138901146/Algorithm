#include<stdio.h>
#include<malloc.h>

long long *min_tree=NULL, *sum_tree=NULL, *lazy=NULL;

void init(long long *arr,int node,int start,int end)
{
	if(start==end)
		sum_tree[node]=min_tree[node]=arr[start];
	else
	{
		init(arr,node<<1,start,start+end>>1);
		init(arr,node<<1|1,(start+end>>1)+1,end);

		sum_tree[node]=sum_tree[node<<1]+sum_tree[node<<1|1];
		min_tree[node]=min_tree[node<<1]<min_tree[node<<1|1]?min_tree[node<<1]:min_tree[node<<1|1];
	}
}

void update_lazy(int node,int start,int end)
{
	if(lazy[node])
	{
		sum_tree[node]+=(end-start+1)*lazy[node];
		min_tree[node]+=lazy[node];
		if(start!=end)
		{
			lazy[node<<1]+=lazy[node];
			lazy[node<<1|1]+=lazy[node];
		}
		lazy[node]=0;
	}
}

long long get(int node,int start,int end,int left,int right,int is_sum)
{
	update_lazy(node,start,end);

	if(left>end || right<start)
		return is_sum?0:1000000000000;
	if(left<=start && end<=right)
		return is_sum?sum_tree[node]:min_tree[node];

	long long left_value=get(node<<1,start,start+end>>1,left,right,is_sum), right_value=get(node<<1|1,(start+end>>1)+1,end,left,right,is_sum);

	return is_sum?left_value+right_value:left_value<right_value?left_value:right_value;
}

void update_range(int node,int start,int end,int left,int right,long long diff)
{
	update_lazy(node,start,end);

	if(left>end || right<start)
		return;
	if(left<=start && end<=right)
	{
		sum_tree[node]+=(end-start+1)*diff;
		min_tree[node]+=diff;
		if(start!=end)
		{
			lazy[node<<1]+=diff;
			lazy[node<<1|1]+=diff;
		}

		return;
	}

	update_range(node<<1,start,start+end>>1,left,right,diff);
	update_range(node<<1|1,(start+end>>1)+1,end,left,right,diff);
	sum_tree[node]=sum_tree[node<<1]+sum_tree[node<<1|1];
	min_tree[node]=min_tree[node<<1]<min_tree[node<<1|1]?min_tree[node<<1]:min_tree[node<<1|1];
}

int main(void)
{
	int N, Q, A, B, C, size=0;
	char operation;
	long long *haybales=NULL;

	scanf("%d%d", &N, &Q);

	while((1<<size)<=N)
		++size;
	size=1<<++size;
	haybales=(long long *)malloc((N+1)*sizeof(long long));
	min_tree=(long long *)calloc(size,sizeof(long long));
	sum_tree=(long long *)calloc(size,sizeof(long long));

	for(int n=1;n<=N;++n)
		scanf("%lld", &haybales[n]);
	init(haybales,1,1,N);

	free(haybales);
	lazy=(long long *)calloc(size,sizeof(long long));

	while(Q--)
	{
		getchar();
		scanf("%c%d%d", &operation, &A, &B);

		if(operation=='P')
		{
			scanf("%d", &C);
			update_range(1,1,N,A,B,C);
		}
		else
			printf("%lld\n", get(1,1,N,A,B,operation=='S'));

	}

	free(min_tree);
	free(sum_tree);
	free(lazy);
	return 0;
}