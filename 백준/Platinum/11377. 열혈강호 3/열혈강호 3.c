#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

int *work=NULL, **employee=NULL, *employee_count=NULL;
bool *visited=NULL;

bool dfs(int current)
{
	for(int i=0;i<employee_count[current];++i)
		if(!visited[employee[current][i]])
		{
			visited[employee[current][i]]=true;

			if(work[employee[current][i]]==0 || dfs(work[employee[current][i]]))
			{
				work[employee[current][i]]=current;
				return true;
			}
		}

	return false;
}

int main(void)
{
	int N, M, K, count=0;

	scanf("%d%d%d", &N, &M, &K);
	employee=(int **)malloc((N+1)*sizeof(int *));
	employee_count=(int *)malloc((N+1)*sizeof(int));
	work=(int *)calloc(M+1,sizeof(int));
	visited=(bool *)malloc((M+1)*sizeof(bool));

	for(int n=1;n<=N;++n)
	{
		scanf("%d", &employee_count[n]);
		employee[n]=(int *)malloc(employee_count[n]*sizeof(int));

		for(int i=0;i<employee_count[n];++i)
			scanf("%d", &employee[n][i]);
	}

	for(int n=1;n<=N;++n)
	{
		for(int m=1;m<=M;++m)
			visited[m]=false;
		dfs(n);
	}
	for(int n=1;n<=N&&K;++n)
	{
		for(int m=1;m<=M;++m)
			visited[m]=false;
		K-=dfs(n);
	}

	while(M)
		count+=work[M--]>0;

	printf("%d", count);
	while(N)
		free(employee[N--]);
	free(employee);
	free(employee_count);
	free(work);
	free(visited);
	return 0;
}