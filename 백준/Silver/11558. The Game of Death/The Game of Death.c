#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	while(T--)
	{
		int N, *A=NULL, current=1, K=0;
		bool *visited=NULL;

		scanf("%d", &N);
		A=(int *)calloc(N+1,sizeof(int));
		visited=(bool *)calloc(N+1,sizeof(int));

		for(int i=1;i<=N;++i)
			scanf("%d", &A[i]);

		while(current!=N&&!visited[current])
		{
			visited[current]=true;
			current=A[current];
			++K;
		}

		printf("%d\n", current==N?K:0);
		free(visited);
		free(A);
	}

	return 0;
}