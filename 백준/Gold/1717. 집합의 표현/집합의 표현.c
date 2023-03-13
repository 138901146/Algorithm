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
	int n, m, a, b, oper;

	scanf("%d%d", &n, &m);
	set=(int *)malloc((n+1)*sizeof(int));
	for(int i=0;i<=n;i++)
		set[i]=i;

	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d", &oper, &a, &b);
		if(oper==0)
			union_set(a,b);
		else
			printf("%s\n", find_set(a)==find_set(b)?"YES":"NO");
	}

	free(set);
	return 0;
}