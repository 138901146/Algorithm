#include<stdio.h>
#include<malloc.h>

int *cow=NULL, *min=NULL, *max=NULL;

void init_min(int node,int start,int end)
{
	if(start==end)
		min[node]=cow[start];
	else
	{
		init_min(node<<1,start,(start+end)>>1);
		init_min(node<<1|1,((start+end)>>1)+1,end);
		min[node]=min[node<<1]<min[node<<1|1]?min[node<<1]:min[node<<1|1];
	}
}

void init_max(int node,int start,int end)
{
	if(start==end)
		max[node]=cow[start];
	else
	{
		init_max(node<<1,start,(start+end)>>1);
		init_max(node<<1|1,((start+end)>>1)+1,end);
		max[node]=max[node<<1]>max[node<<1|1]?max[node<<1]:max[node<<1|1];
	}
}

int get_min(int node,int start,int end,int left,int right)
{
	if(left>end || right<start)
		return 1000000000;
	else if(left<=start && end<=right)
		return min[node];
	else
	{
		int left_value=get_min(node<<1,start,(start+end)>>1,left,right), right_value=get_min(node<<1|1,((start+end)>>1)+1,end,left,right);
		return left_value<right_value?left_value:right_value;
	}
}

int get_max(int node,int start,int end,int left,int right)
{
	if(left>end || right<start)
		return -1000000000;
	else if(left<=start && end<=right)
		return max[node];
	else
	{
		int left_value=get_max(node<<1,start,(start+end)>>1,left,right), right_value=get_max(node<<1|1,((start+end)>>1)+1,end,left,right);
		return left_value>right_value?left_value:right_value;
	}
}

int main(void)
{
	int N, Q, size=0, A, B;
	scanf("%d%d", &N, &Q);
	cow=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;n++)
		scanf("%d", &cow[n]);

	while((1<<size)<N)
		size++;
	size++;
	min=(int *)malloc((1<<size)*sizeof(int));
	max=(int *)malloc((1<<size)*sizeof(int));

	init_min(1,0,N-1);
	init_max(1,0,N-1);

	while(Q--)
	{
		scanf("%d%d", &A, &B);
		printf("%d\n", get_max(1,0,N-1,A-1,B-1)-get_min(1,0,N-1,A-1,B-1));
	}

	free(cow);
	free(min);
	free(max);
	return 0;
}