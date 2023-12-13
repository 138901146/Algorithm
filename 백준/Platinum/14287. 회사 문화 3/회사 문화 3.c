#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int origin, descendant;
}
node;

int size=0, *junior_count=NULL, **junior=NULL;
node *arr=NULL;

int make_tree_range(int current)
{
	for(int i=0;i<junior_count[current];++i)
	{
		arr[junior[current][i]].origin=++size;
		arr[junior[current][i]].descendant=make_tree_range(junior[current][i]);
	}

	return arr[current].descendant=size;
}

int get(int *tree,int node,int start,int end,int left,int right)
{
	if(left>end || right<start)
		return 0;
	else if(left<=start && end<=right)
		return tree[node];
	else
		return get(tree,node<<1,start,(start+end)>>1,left,right)+get(tree,node<<1|1,((start+end)>>1)+1,end,left,right);
}

void update(int *tree,int node,int start,int end,int index,int value)
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
		update(tree,node<<1,start,(start+end)>>1,index,value);
		update(tree,node<<1|1,((start+end)>>1)+1,end,index,value);
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
}

int main(void)
{
	int n, m, *senior=NULL, *tree=NULL, operation, employee, w;

	scanf("%d%d", &n, &m);
	senior=(int *)malloc((n+1)*sizeof(int));
	junior=(int **)malloc((n+1)*sizeof(int *));
	junior_count=(int *)calloc(n+1,sizeof(int));

	scanf("%d", &senior[1]);
	for(int i=2;i<=n;++i)
	{
		scanf("%d", &senior[i]);
		++junior_count[senior[i]];
	}

	for(int i=1;i<=n;++i)
	{
		junior[i]=(int *)malloc(junior_count[i]*sizeof(int));
		junior_count[i]=0;
	}

	for(int i=2;i<=n;++i)
		junior[senior[i]][junior_count[senior[i]]++]=i;

	free(senior);
	arr=(node *)malloc((n+1)*sizeof(node));

	arr[1].origin=0;
	make_tree_range(1);

	for(int i=1;i<=n;++i)
		free(junior[i]);
	free(junior_count);
	free(junior);

	size=0;
	while((1<<size)<n)
		++size;
	size=1<<++size;
	tree=(int *)calloc(size,sizeof(int));

	while(m--)
	{
		scanf("%d%d", &operation, &employee);

		if(operation==1)
		{
			scanf("%d", &w);
			update(tree,1,0,n-1,arr[employee].origin,w);
		}
		else
			printf("%d\n", get(tree,1,0,n-1,arr[employee].origin,arr[employee].descendant));
	}

	free(tree);
	free(arr);
	return 0;
}