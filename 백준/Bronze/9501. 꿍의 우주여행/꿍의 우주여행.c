#include<stdio.h>

int main(void)
{
	int T, N, D;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int count=0, v, f, c;

		scanf("%d %d", &N, &D);

		for(int n=0;n<N;n++)
		{
			scanf("%d %d %d", &v, &f, &c);
			count+=(float)v*f/c>=D;
		}

		printf("%d\n", count);
	}

	return 0;
}