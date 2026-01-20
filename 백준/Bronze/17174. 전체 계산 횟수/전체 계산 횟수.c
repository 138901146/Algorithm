#include<stdio.h>

int main(void)
{
	int N, M, total=0;

	scanf("%d%d", &N, &M);

	while(M<=N)
	{
		total+=N;
		N/=M;
	}

	printf("%d", total+N);
	return 0;
}