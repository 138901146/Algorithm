#include<stdio.h>

int main(void)
{
	int N, A, B, C, sum, best=999;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d%d%d", &A, &B, &C);

		sum=A+B+C;

		if(511<sum)
			best=sum<best?sum:best;
	}

	printf("%d", best==999?-1:best);
	return 0;
}