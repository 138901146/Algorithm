#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

int main(void)
{
	int N, K=0, *A=NULL, *parent=NULL;
	bool *visited=NULL;

	scanf("%d", &N);

	A=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &A[i]);

	for(int i=0;i<N;++i)
		K=A[i]<K?K:A[i];

	visited=(bool *)calloc(++K,sizeof(bool));
	parent=(int *)malloc(K*sizeof(int));

	visited[A[0]]=true;
	parent[A[0]]=-1;

	for(int i=1;i<N;++i)
		if(!visited[A[i]])
		{
			visited[A[i]]=true;
			parent[A[i]]=A[i-1];
		}

	printf("%d\n", K);
	for(int i=0;i<K;++i)
		printf("%d ", parent[i]);
	free(A);
	free(parent);
	free(visited);
	return 0;
}