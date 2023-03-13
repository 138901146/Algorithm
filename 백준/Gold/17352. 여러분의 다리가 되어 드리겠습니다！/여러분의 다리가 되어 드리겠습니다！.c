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
	int N, x, y;

	scanf("%d", &N);
	set=(int *)malloc((N+1)*sizeof(int));
	for(int n=0;n<=N;n++)
		set[n]=n;

	for(int n=0;n<N-2;n++)
	{
		scanf("%d%d", &x, &y);
		union_set(x,y);
	}

	x=find_set(1);
	for(int n=2;n<=N;n++)
		if(find_set(n)!=x)
		{
			printf("1 %d\n", n);
			break;
		}

	free(set);
	return 0;
}