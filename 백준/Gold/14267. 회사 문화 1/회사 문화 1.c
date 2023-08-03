#include<stdio.h>
#include<malloc.h>

int *superior=NULL, *compliment=NULL, **child=NULL, *child_count=NULL;

void compliment_sum(int current)
{
	compliment[current]+=compliment[superior[current]];

	for(int i=0;i<child_count[current];i++)
		compliment_sum(child[current][i]);
}

int main(void)
{
	int n, m, employee, w;

	scanf("%d%d", &n, &m);
	superior=(int *)malloc((n+1)*sizeof(int));
	child_count=(int *)calloc(n+1,sizeof(int));
	child=(int **)malloc((n+1)*sizeof(int *));
	compliment=(int *)calloc(n+1,sizeof(int));

	scanf("%d", &superior[1]);
	superior[1]=0;
	for(int i=2;i<=n;i++)
	{
		scanf("%d", &superior[i]);
		child_count[superior[i]]++;
	}

	for(int i=1;i<=n;i++)
	{
		child[i]=(int *)malloc(child_count[i]*sizeof(int));
		child_count[i]=0;
	}

	for(int i=2;i<=n;i++)
		child[superior[i]][child_count[superior[i]]++]=i;

	for(int i=0;i<m;i++)
	{
		scanf("%d%d", &employee, &w);
		compliment[employee]+=w;
	}

	compliment_sum(1);

	for(int i=1;i<=n;i++)
	{
		printf("%d ", compliment[i]);
		free(child[i]);
	}
	free(child);
	free(child_count);
	free(superior);
	free(compliment);
	return 0;
}