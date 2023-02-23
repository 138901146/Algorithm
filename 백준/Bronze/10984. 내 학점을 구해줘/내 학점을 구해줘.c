#include<stdio.h>

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int i=0;i<T;i++)
	{
		int N, C, total=0;
		float  G, GPA=0.0;

		scanf("%d", &N);

		for(int j=0;j<N;j++)
		{
			scanf("%d %f", &C, &G);

			total+=C;
			GPA+=C*G;
		}

		GPA/=total;

		printf("%d %.1f\n", total, GPA);
	}

	return 0;
}