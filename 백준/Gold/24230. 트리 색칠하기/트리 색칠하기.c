#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int a, b;
}
edge;

int *parent=NULL, **child=NULL, *child_count, *C=NULL, count=0;

void color_tree(int current,int color)
{
	if(C[current]!=color)
		++count;

	for(int i=0;i<child_count[current];++i)
	{
		int next=child[current][i];

		if(parent[current]!=next)
		{
			parent[next]=current;
			color_tree(next,C[current]);
		}
	}

	free(child[current]);
}

int main(void)
{
	int N;
	edge *e=NULL;

	scanf("%d", &N);

	C=(int *)calloc(N+1,sizeof(int));
	child=(int **)malloc((N+1)*sizeof(int *));
	child_count=(int *)calloc(N+1,sizeof(int));
	e=(edge *)malloc((N-1)*sizeof(edge));

	for(int i=1;i<=N;++i)
		scanf("%d", &C[i]);

	for(int i=0;i<N-1;++i)
	{
		scanf("%d%d", &e[i].a, &e[i].b);
		++child_count[e[i].a];
		++child_count[e[i].b];
	}

	for(int i=1;i<=N;++i)
	{
		child[i]=(int *)malloc(child_count[i]*sizeof(int));
		child_count[i]=0;
	}

	for(int i=0;i<N-1;++i)
	{
		child[e[i].a][child_count[e[i].a]++]=e[i].b;
		child[e[i].b][child_count[e[i].b]++]=e[i].a;
	}

	free(e);
	parent=(int *)calloc(N+1,sizeof(int));

	color_tree(1,0);

	printf("%d", count);
	free(child);
	free(child_count);
	free(parent);
	free(C);
	return 0;
}