#include<stdio.h>
#include<malloc.h>

int *parent=NULL, *depth=NULL, **child=NULL, *column=NULL, column_count=1, depth_count=0;

void find(int current)
{
	depth[current]=depth[parent[current]]+1;
	depth_count=depth[current]>depth_count?depth[current]:depth_count;

	if(child[current][0]>0)
		find(child[current][0]);
	column[current]=column_count++;
	if(child[current][1]>0)
		find(child[current][1]);
}

int main(void)
{
	int N, *max=NULL, *min=NULL, node, root, largest=1;

	scanf("%d", &N);
	parent=(int *)calloc(N+1,sizeof(int));
	child=(int **)malloc((N+1)*sizeof(int *));
	depth=(int *)malloc((N+1)*sizeof(int));
	column=(int *)malloc((N+1)*sizeof(int));

	for(int n=0;n<N;n++)
	{
		scanf("%d", &node);
		child[node]=(int *)malloc(2*sizeof(int));
		for(int i=0;i<2;i++)
		{
			scanf("%d", &child[node][i]);
			if(child[node][i]>0)
				parent[child[node][i]]=node;
		}
	}

	for(int n=1;n<=N;n++)
		if(!parent[n])
		{
			root=n;
			break;
		}

	depth[0]=0;
	find(root);

	max=(int *)malloc((depth_count+1)*sizeof(int));
	min=(int *)malloc((depth_count+1)*sizeof(int));

	for(int i=1;i<=depth_count;i++)
	{
		max[i]=-1;
		min[i]=1000000;
	}

	for(int n=1;n<=N;n++)
	{
		max[depth[n]]=column[n]>=max[depth[n]]?column[n]:max[depth[n]];
		min[depth[n]]=column[n]<min[depth[n]]?column[n]:min[depth[n]];
		free(child[n]);
	}

	for(int i=1;i<=depth_count;i++)
		largest=max[i]-min[i]>max[largest]-min[largest]?i:largest;

	printf("%d %d\n", largest, max[largest]-min[largest]+1);
	free(child);
	free(max);
	free(min);
	free(parent);
	free(depth);
	free(column);
	return 0;
}