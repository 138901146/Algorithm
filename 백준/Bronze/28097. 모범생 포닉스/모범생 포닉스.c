#include<stdio.h>

int main(void)
{
	int N, T, total;

	scanf("%d", &N);

	total=N-1<<3;

	while(N--)
	{
		scanf("%d", &T);
		total+=T;
	}

	printf("%d %d", total/24, total%24);
	return 0;
}