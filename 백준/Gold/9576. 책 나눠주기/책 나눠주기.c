#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

int *book=NULL, *a=NULL, *b=NULL;
bool *visited=NULL;

bool dfs(int current)
{
	for(int i=a[current];i<=b[current];i++)
		if(!visited[i])
		{
			visited[i]=true;

			if(book[i]==0 || dfs(book[i]))
			{
				book[i]=current;
				return true;
			}
		}

	return false;
}

int main(void)
{
	int T, N, M, count;

	scanf("%d", &T);

	while(T--)
	{
		count=0;

		scanf("%d%d", &N, &M);

		book=(int *)calloc(N+1,sizeof(int));
		a=(int *)malloc((M+1)*sizeof(int));
		b=(int *)malloc((M+1)*sizeof(int));
		visited=(bool *)malloc((N+1)*sizeof(bool));

		for(int m=1;m<=M;m++)
			scanf("%d%d", &a[m], &b[m]);

		for(int m=1;m<=M;m++)
		{
			for(int n=1;n<=N;n++)
				visited[n]=false;
			dfs(m);
		}

		while(N)
			count+=book[N--]>0;

		printf("%d\n", count);
		free(book);
		free(a);
		free(b);
		free(visited);
	}

	return 0;
}