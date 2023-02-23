#include<stdio.h>

int main(void)
{
	int T, N, C;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		scanf("%d %d", &N, &C);
		printf("%d\n", N/C+(N%C!=0));
	}

	return 0;
}