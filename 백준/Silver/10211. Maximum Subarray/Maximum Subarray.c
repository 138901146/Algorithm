#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	while(T--)
	{
		int N, X, sum=0, max=-1000000;

		scanf("%d", &N);

		while(N--)
		{
			scanf("%d", &X);

			sum=X+sum>X?X+sum:X;
			max=max>sum?max:sum;
		}

		printf("%d\n", max);
	}

	return 0;
}