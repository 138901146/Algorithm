#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int U, V;
}
node;

int **child=NULL, *child_count=NULL, *parent=NULL;
double *exp=NULL;

void make_tree(int current)
{
	for(int i=0;i<child_count[current];++i)
	{
		int next=child[current][i];

		if(next!=parent[current])
		{
			exp[next]=exp[current]/(child_count[current]-(current!=1));
			parent[next]=current;
			make_tree(next);
		}
	}
}

int main(void)
{
	int N, W, count=0;
	node *edge=NULL;
	double answer=0;

	scanf("%d%d", &N, &W);
	child=(int **)malloc((N+1)*sizeof(int *));
	child_count=(int *)calloc(N+1,sizeof(int));
	parent=(int *)calloc(N+1,sizeof(int));
	edge=(node *)malloc((N-1)*sizeof(node));

	for(int i=0;i<N-1;++i)
	{
		scanf("%d%d", &edge[i].U, &edge[i].V);
		++child_count[edge[i].U];
		++child_count[edge[i].V];
	}

	for(int i=1;i<=N;++i)
	{
		child[i]=(int *)malloc(child_count[i]*sizeof(int));
		child_count[i]=0;
	}

	for(int i=0;i<N-1;++i)
	{
		child[edge[i].U][child_count[edge[i].U]++]=edge[i].V;
		child[edge[i].V][child_count[edge[i].V]++]=edge[i].U;
	}
	free(edge);

	exp=(double *)malloc((N+1)*sizeof(double));
	exp[1]=W;

	make_tree(1);

	for(int i=2;i<=N;++i)
	{
		if(child_count[i]==1)
		{
			answer+=exp[i];
			++count;
		}
		free(child[i]);
	}
	printf("%lf", answer/count);
	free(child[1]);
	free(child);
	free(child_count);
	free(parent);
	free(exp);
	return 0;
}