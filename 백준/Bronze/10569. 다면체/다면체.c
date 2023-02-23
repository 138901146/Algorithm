#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int V, E;

		scanf("%d %d", &V, &E);

		printf("%d\n", 2-V+E);
	}

	return 0;
}