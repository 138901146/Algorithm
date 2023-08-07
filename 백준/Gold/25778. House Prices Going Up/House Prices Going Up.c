#include<stdio.h>
#include<malloc.h>

void init(int *arr,unsigned long long *tree,int node,int start,int end)
{
	if(start==end)
		tree[node]=arr[end];
	else
	{
		init(arr,tree,node<<1,start,(start+end)>>1);
		init(arr,tree,node<<1|1,((start+end)>>1)+1,end);
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
}

unsigned long long get(unsigned long long *tree,int node,int start,int end,int left,int right)
{
	if(start>right || end<left)
		return 0;
	else if(left<=start && end<=right)
		return tree[node];
	else
		return get(tree,node<<1,start,(start+end)>>1,left,right)+get(tree,node<<1|1,((start+end)>>1)+1,end,left,right);
}

void update(unsigned long long *tree,int node,int start,int end,int index,int diff)
{
	if(index<start || index>end)
		return;
	else if(start==end)
		tree[node]+=diff;
	else
	{
		update(tree,node<<1,start,(start+end)>>1,index,diff);
		update(tree,node<<1|1,((start+end)>>1)+1,end,index,diff);
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
}

int main(void)
{
	int n, t, *price=NULL, size=0, x, y;
	unsigned long long *tree=NULL;
	char operation;

	scanf("%d", &n);
	while((1<<size)<n)
		size++;
	size++;

	price=(int *)malloc(n*sizeof(int));
	tree=(unsigned long long *)malloc((1<<size)*sizeof(unsigned long long));

	for(int i=0;i<n;i++)
		scanf("%d", &price[i]);

	init(price,tree,1,0,n-1);

	scanf("%d", &t);

	while(t--)
	{
		getchar();
		scanf("%c%d%d", &operation, &x, &y);

		if(operation=='U')
			update(tree,1,0,n-1,x-1,y);
		else
			printf("%llu\n", get(tree,1,0,n-1,x-1,y-1));
	}

	free(price);
	free(tree);
	return 0;
}