#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int a, b;
}
flight;

int *parent=NULL, **adjacent_list=NULL, *adjacent_list_count=NULL, count;

void make_tree(int current)
{
	for(int i=0;i<adjacent_list_count[current];++i)
	{
		int next=adjacent_list[current][i];

		if(next!=1&&!parent[next])
		{
			parent[next]=current;
			++count;
			make_tree(next);
		}
	}
}

int main(void)
{
	int T, N, M;
	flight *plane=NULL;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d%d", &N, &M);

		plane=(flight *)malloc(M*sizeof(flight));
		adjacent_list=(int **)malloc((N+1)*sizeof(int *));
		adjacent_list_count=(int *)calloc(N+1,sizeof(int));
		parent=(int *)calloc(N+1,sizeof(int));

		for(int m=0;m<M;++m)
		{
			scanf("%d%d", &plane[m].a, &plane[m].b);
			++adjacent_list_count[plane[m].a];
			++adjacent_list_count[plane[m].b];
		}

		for(int n=1;n<=N;++n)
		{
			adjacent_list[n]=(int *)malloc(adjacent_list_count[n]*sizeof(int));
			adjacent_list_count[n]=0;
		}

		for(int m=0;m<M;++m)
		{
			adjacent_list[plane[m].a][adjacent_list_count[plane[m].a]++]=plane[m].b;
			adjacent_list[plane[m].b][adjacent_list_count[plane[m].b]++]=plane[m].a;
		}
		free(plane);

		count=0;
		make_tree(1);

		for(int n=1;n<=N;++n)
			free(adjacent_list[n]);
		free(adjacent_list_count);
		free(parent);
		printf("%d\n", count);
	}

	return 0;
}