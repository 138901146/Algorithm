#include<stdio.h>

int main(void)
{
	int T, N;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &N);
		printf("%s\n", (N+1)%(N%100)?"Bye":"Good");
	}

	return 0;
}