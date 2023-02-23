#include<stdio.h>

int main(void)
{
	int K, C, M, N;

	scanf("%d", &K);
	scanf("%d", &C);

	for(int c=0;c<C;c++)
	{
		scanf("%d %d", &M, &N);
		printf("%d\n",M>N?2*M<N+K+3:M<N?2*N<M+K+2:1);
	}

	return 0;
}