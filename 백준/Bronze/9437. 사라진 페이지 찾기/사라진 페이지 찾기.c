#include<stdio.h>

int main(void)
{
	int N, P;

	scanf("%d", &N);
	while(N!=0)
	{
		scanf("%d", &P);
		if(2*P<=N)
			if(P%2==1)
				printf("%d %d %d\n", P+1, N-P, N+1-P);
			else
				printf("%d %d %d\n", P-1, N+1-P, N+2-P);
		else
			if(P%2==0)
				printf("%d %d %d\n", N+1-P, N+2-P, P-1);
			else
				printf("%d %d %d\n", N-P, N+1-P, P+1);
		scanf("%d", &N);
	}

	return 0;
}