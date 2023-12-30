#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int x, y, index;
}
location;

int compare_x(const void *x,const void *y)
{
	return ((location *)x)->x<((location *)y)->x?-1:((location *)x)->x>((location *)y)->x?1:((location *)x)->y>((location *)y)->y?-1:1;
}

int compare_y(const void *x,const void *y)
{
	return ((location *)x)->y<((location *)y)->y?1:((location *)x)->y>((location *)y)->y?-1:((location *)x)->x<((location *)y)->x?-1:1;
}

int get(int *tree,int node,int start,int end,int left,int right)
{
	if(left>end || right<start)
		return 0;
	else if(left<=start && end<=right)
		return tree[node];
	else
		return get(tree,node<<1,start,start+end>>1,left,right)+get(tree,node<<1|1,(start+end>>1)+1,end,left,right);
}

void update(int *tree,int node,int start,int end,int index)
{
	if(index<start || index>end)
		return;
	else if(start==end)
	{
		++tree[node];
		return;
	}
	else
	{
		update(tree,node<<1,start,start+end>>1,index);
		update(tree,node<<1|1,(start+end>>1)+1,end,index);
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
}

int main(void)
{
	int T, n, *order=NULL, *tree=NULL, count, size;
	long long answer;
	location *island=NULL;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &n);
		island=(location *)malloc(n*sizeof(location));
		order=(int *)malloc(n*sizeof(int));

		for(int i=0;i<n;++i)
			scanf("%d%d", &island[i].x, &island[i].y);
		qsort((void *)island,(size_t)n,sizeof(location),compare_x);

		for(int i=0;i<n;++i)
			island[i].index=i;
		qsort((void *)island,(size_t)n,sizeof(location),compare_y);

		answer=count=size=0;
		for(int i=0;i<n;++i)
			order[island[i].index]=i;

		for(int i=1;i<n;++i)
		{
			count+=island[order[i]].x==island[order[i-1]].x;
			island[order[i]].index=i-count;
		}
		free(order);

		count=n-1-count;
		while((1<<size)<=count)
			++size;
		tree=(int *)calloc(1<<++size,sizeof(int));

		for(int i=0;i<n;++i)
		{
			answer+=get(tree,1,0,count,0,island[i].index);
			update(tree,1,0,count,island[i].index);
		}

		printf("%lld\n", answer);
		free(island);
		free(tree);
	}

	return 0;
}