#include<stdio.h>

int sumFunction(int N)
{
	return N<3?N:N==3?4:sumFunction(N-1)+sumFunction(N-2)+sumFunction(N-3);
}

int main(void)
{
	int T;

	scanf("%d", &T);

	for(int i=0;i<T;i++)
	{
		int n;

		scanf("%d", &n);
		printf("%d\n", sumFunction(n));
	}

	return 0;
}