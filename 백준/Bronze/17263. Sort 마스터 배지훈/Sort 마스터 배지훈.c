#include<stdio.h>

int main(void)
{
	int N, A, max=0;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d", &A);
		max=A<max?max:A;
	}

	printf("%d", max);
	return 0;
}