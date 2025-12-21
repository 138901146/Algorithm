#include<stdio.h>

int main(void)
{
	int N, L, D[100], R[100], G[100], elapsed=0, current=0, state;

	scanf("%d%d", &N, &L);
	for(int i=0;i<N;++i)
		scanf("%d%d%d", &D[i], &R[i], &G[i]);

	for(int i=0;i<N;++i)
	{
		elapsed+=D[i]-current;
		state=elapsed%(R[i]+G[i]);

		if(state<R[i])
			elapsed+=R[i]-state;
		current=D[i];
	}

	elapsed+=L-current;

	printf("%d", elapsed);
	return 0;
}