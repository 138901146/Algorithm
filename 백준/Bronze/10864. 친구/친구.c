#include<stdio.h>

int main(void)
{
	int N, M, A, B, friend[1001]={0};

	scanf("%d%d", &N, &M);

	while(M--)
	{
		scanf("%d%d", &A, &B);
		++friend[A];
		++friend[B];
	}

	for(int n=1;n<=N;++n)
		printf("%d\n", friend[n]);
	return 0;
}