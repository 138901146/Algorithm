#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int N, M;

		scanf("%d %d", &N, &M);

		printf("%d\n", (N>=12&&M>=4)?11*M+4:-1);
	}

	return 0;
}