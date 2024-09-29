#include<stdio.h>

int main(void)
{
	int N, X, A[2], current=0, previous=1, min;

	scanf("%d%d", &N, &X);

	scanf("%d%d", &A[0], &A[1]);

	min=A[0]+A[1];

	--N;
	while(--N)
	{
		scanf("%d", &A[current]);

		min=A[0]+A[1]<min?A[0]+A[1]:min;

		current^=1;
		previous^=1;
	}

	printf("%d", min*X);
	return 0;
}