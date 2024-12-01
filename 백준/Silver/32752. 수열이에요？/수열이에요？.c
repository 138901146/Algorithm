#include<stdio.h>

int main(void)
{
	int N, L, R, A, max=0, range_max=0, range_min=2000000000;

	scanf("%d%d%d", &N, &L, &R);
	--L;

	for(int i=0;i<L;++i)
	{
		scanf("%d", &A);

		if(A<max)
		{
			printf("0");
			return 0;
		}

		max=A;
	}

	for(int i=L;i<R;++i)
	{
		scanf("%d", &A);

		range_max=A<range_max?range_max:A;
		range_min=A<range_min?A:range_min;

		if(range_min<max)
		{
			printf("0");
			return 0;
		}
	}

	max=range_max;
	for(int i=R;i<N;++i)
	{
		scanf("%d", &A);

		if(A<max)
		{
			printf("0");
			return 0;
		}
	}

	printf("1");
	return 0;
}