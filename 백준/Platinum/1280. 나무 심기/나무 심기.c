#include<stdio.h>

#define SIZE 524288
#define MOD 1000000007

long long left_sum[SIZE]={0}, right_sum[SIZE]={0}, total[SIZE]={0};

long long get(long long *tree,int node,int start,int end,int left,int right)
{
	if(left>end || right<start)
		return 0;
	else if(left<=start && end<=right)
		return tree[node];
	else
		return get(tree,node<<1,start,start+end>>1,left,right)+get(tree,node<<1|1,(start+end>>1)+1,end,left,right);
}

void update(long long *tree,int node,int start,int end,int index,long long value)
{
	if(index<start || index>end)
		return;
	else if(start==end)
	{
		tree[node]+=value;
		return;
	}
	else
	{
		update(tree,node<<1,start,start+end>>1,index,value);
		update(tree,node<<1|1,(start+end>>1)+1,end,index,value);
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
}

int main(void)
{
	int N, location;
	long long cost=1;

	scanf("%d", &N);

	scanf("%d", &location);

	update(left_sum,1,0,200000,location,location);
	update(right_sum,1,0,200000,location,200000-location);
	update(total,1,0,200000,location,1);

	while(--N)
	{
		scanf("%d", &location);

		cost=(cost*((get(total,1,0,200000,0,location)*location-get(left_sum,1,0,200000,0,location)+get(total,1,0,200000,location,200000)*(200000-location)-get(right_sum,1,0,200000,location,200000))%MOD))%MOD;

		update(left_sum,1,0,200000,location,location);
		update(right_sum,1,0,200000,location,200000-location);
		update(total,1,0,200000,location,1);
	}

	printf("%lld", cost);
	return 0;
}