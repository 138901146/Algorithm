#include<stdio.h>

int main(void)
{
	int N, M, five, x=0;

	scanf("%d", &N);

	while(N)
	{
		for(M=0,five=5;five<=N;five*=5)
			M+=N/five;

		printf("Case #%d: %d\n", ++x, M);
		scanf("%d", &N);
	}

	return 0;
}