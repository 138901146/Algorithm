#include<stdio.h>

int main(void)
{
	int test_case, N, p;

	scanf("%d", &test_case);

	while(test_case--)
	{
		int N, p, sum=-1234, sum_i=0, sum_j=0, max=-1234, max_i=0, max_j=0;

		scanf("%d", &N);

		for(int i=1;i<=N;++i)
		{
			scanf("%d", &p);

			sum_i=0<=sum?sum_i:i;
			sum_j=i;
			sum=0<sum?p+sum:p;

			max_i=max<sum?sum_i:max_i;
			max_j=max<sum?sum_j:max_j;
			max=max<sum?sum:max;
		}

		printf("%d %d\n", max_i, max_j);
	}

	return 0;
}