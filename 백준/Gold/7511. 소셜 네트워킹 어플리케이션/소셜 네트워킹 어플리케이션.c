#include<stdio.h>
#include<stdlib.h>

int *set=NULL;

int find_set(int x)
{
	if(x==set[x])
		return x;
	else
		return set[x]=find_set(set[x]);
}

void union_set(int x,int y)
{
	if(find_set(x)!=find_set(y))
		set[find_set(y)]=find_set(x);
}

int main(void)
{
	int T, n, k, a, b, m;

	scanf("%d", &T);
	for(int t=1;t<=T;t++)
	{
		scanf("%d", &n);
		set=(int *)malloc(n*sizeof(int));
		for(int i=0;i<n;i++)
			set[i]=i;

		scanf("%d", &k);
		for(int i=0;i<k;i++)
		{
			scanf("%d%d", &a, &b);
			union_set(a,b);
		}

		scanf("%d", &m);
		printf("Scenario %d:\n", t);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d", &a, &b);
			printf("%d\n", find_set(a)==find_set(b));
		}
		printf("\n");
		free(set);
	}

	return 0;
}