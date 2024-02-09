#include<stdio.h>
#include<stdbool.h>
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

void update_lazy(int *tree,int *lazy,int node,int start,int end)
{
	if(lazy[node]!=0)
	{
		tree[node]+=(end-start+1)*lazy[node];
		if(start!=end)
		{
			lazy[node<<1]+=lazy[node];
			lazy[node<<1|1]+=lazy[node];
		}
		lazy[node]=0;
	}
}

int get_down(int *tree,int *lazy,int node,int start,int end,int target)
{
	update_lazy(tree,lazy,node,start,end);

	if(target>end || target<start)
		return 0;
	if(target<=start && end<=target)
		return tree[node];

	return get_down(tree,lazy,node<<1,start,start+end>>1,target)+get_down(tree,lazy,node<<1|1,(start+end>>1)+1,end,target);
}

void update_range(int *tree,int *lazy,int node,int start,int end,int left,int right,int diff)
{
	update_lazy(tree,lazy,node,start,end);

	if(left>end || right<start)
		return;
	if(left<=start && end<=right)
	{
		tree[node]+=(end-start+1)*diff;
		if(start!=end)
		{
			lazy[node<<1]+=diff;
			lazy[node<<1|1]+=diff;
		}

		return;
	}

	update_range(tree,lazy,node<<1,start,start+end>>1,left,right,diff);
	update_range(tree,lazy,node<<1|1,(start+end>>1)+1,end,left,right,diff);
	tree[node]=tree[node<<1]+tree[node<<1|1];
}

int get_up(int *tree,int node,int start,int end,int left,int right)
{
	if(left>end || right<start)
		return 0;
	else if(left<=start && end<=right)
		return tree[node];
	else
		return get_up(tree,node<<1,start,start+end>>1,left,right)+get_up(tree,node<<1|1,(start+end>>1)+1,end,left,right);
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
		update(tree,node<<1,start,start+end>>1,index,value);
		update(tree,node<<1|1,(start+end>>1)+1,end,index,value);
		tree[node]=tree[node<<1]+tree[node<<1|1];
	}
}

int main(void)
{
	int n, m, *senior=NULL, *lazy_tree=NULL, *lazy=NULL, *tree=NULL, operation, employee, w;
	bool down=true;

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
	lazy_tree=(int *)calloc(size,sizeof(int));
	lazy=(int *)calloc(size,sizeof(int));

	while(m--)
	{
		scanf("%d", &operation);

		if(operation==1)
		{
			scanf("%d%d", &employee, &w);

			if(down)
				update_range(lazy_tree,lazy,1,0,n-1,arr[employee].origin,arr[employee].descendant,w);
			else
				update(tree,1,0,n-1,arr[employee].origin,w);
		}
		else if(operation==2)
		{
			scanf("%d", &employee);
			printf("%d\n", get_down(lazy_tree,lazy,1,0,n-1,arr[employee].origin)+get_up(tree,1,0,n-1,arr[employee].origin,arr[employee].descendant));
		}
		else
			down=!down;
	}

	free(tree);
	free(lazy_tree);
	free(lazy);
	free(arr);
	return 0;
}