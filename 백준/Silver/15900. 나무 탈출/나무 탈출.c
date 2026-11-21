#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int a, b;
}
edge;

edge *initial_list=NULL;
int **adjacent_list=NULL, *adjacent_list_count=NULL, *parent=NULL, *depth=NULL;

void make_tree(int current)
{
	for(int i=0;i<adjacent_list_count[current];++i)
	{
		int next=adjacent_list[current][i];

		if(next!=parent[current])
		{
			parent[next]=current;
			depth[next]=depth[current]+1;
			make_tree(next);
		}
	}
}

int main(void)
{
	int N, total=0;

	scanf("%d", &N);

	initial_list=(edge *)malloc((N-1)*sizeof(edge));
	adjacent_list=(int **)malloc((N+1)*sizeof(int *));
	adjacent_list_count=(int *)calloc(N+1,sizeof(int));

	for(int i=0;i<N-1;++i)
	{
		scanf("%d%d", &initial_list[i].a, &initial_list[i].b);
		++adjacent_list_count[initial_list[i].a];
		++adjacent_list_count[initial_list[i].b];
	}

	for(int i=1;i<=N;++i)
	{
		adjacent_list[i]=(int *)malloc(adjacent_list_count[i]*sizeof(int));
		adjacent_list_count[i]=0;
	}

	for(int i=0;i<N-1;++i)
	{
		int a=initial_list[i].a, b=initial_list[i].b;

		adjacent_list[a][adjacent_list_count[a]++]=b;
		adjacent_list[b][adjacent_list_count[b]++]=a;
	}

	free(initial_list);
	parent=(int *)calloc(N+1,sizeof(int));
	depth=(int *)calloc(N+1,sizeof(int));

	make_tree(1);

	for(int i=2;i<=N;++i)
	{
		if(adjacent_list_count[i]==1)
			total+=depth[i];
		free(adjacent_list[i]);
	}
	free(adjacent_list[1]);
	free(adjacent_list);
	free(adjacent_list_count);
	free(parent);
	free(depth);

	printf("%s", total&1?"Yes":"No");
	return 0;
}