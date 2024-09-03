#include<stdio.h>

int main(void)
{
	int T, N, A, B;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &N);

		while(N--)
		{
			scanf("%d%d", &A, &B);
			printf("%d %d\n", A+B, A*B);
		}
	}

	return 0;
}