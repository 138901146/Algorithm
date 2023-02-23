#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int N, temp, sum=0;

		scanf("%d", &N);

		for(int n=0;n<N;n++)
		{
			scanf("%d", &temp);

			sum+=temp;
		}

		printf("%d\n", sum);
	}

	return 0;
}