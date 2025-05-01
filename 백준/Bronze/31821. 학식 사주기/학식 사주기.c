#include<stdio.h>

int main(void)
{
	int N, A[11], M, B, total=0;

	scanf("%d", &N);
	for(int i=1;i<=N;++i)
		scanf("%d", &A[i]);

	scanf("%d", &M);
	while(M--)
	{
		scanf("%d", &B);
		total+=A[B];
	}

	printf("%d", total);
	return 0;
}