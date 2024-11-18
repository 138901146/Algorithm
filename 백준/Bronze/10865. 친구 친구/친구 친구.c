#include<stdio.h>

int main(void)
{
	int N, M, count[100001]={0}, A, B;

	scanf("%d%d", &N, &M);

	while(M--)
	{
		scanf("%d%d", &A, &B);
		++count[A];
		++count[B];
	}

	for(int n=1;n<=N;++n)
		printf("%d\n", count[n]);

	return 0;
}