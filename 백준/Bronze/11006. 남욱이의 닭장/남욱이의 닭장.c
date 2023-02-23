#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int N, M;

		scanf("%d %d", &N, &M);

		printf("%d %d\n", 2*M-N, N-M);
	}

	return 0;
}