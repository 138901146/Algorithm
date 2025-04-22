#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, Q, x, y, *playlist=NULL, *fault=NULL;

	scanf("%d", &N);
	playlist=(int *)calloc(N+1,sizeof(int));
	fault=(int *)calloc(N+1,sizeof(int));

	for(int n=1;n<=N;++n)
		scanf("%d", &playlist[n]);

	for(int n=1;n<N;++n)
		fault[n]=fault[n-1]+(playlist[n+1]<playlist[n]);
	fault[N]=fault[N-1];

	scanf("%d", &Q);
	while(Q--)
	{
		scanf("%d%d", &x, &y);
		printf("%d\n", fault[y-1]-fault[x-1]);
	}

	free(playlist);
	free(fault);
	return 0;
}