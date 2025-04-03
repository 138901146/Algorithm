#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	for(int n=0;n<N;++n)
		printf("%d ", n&1?N-(n>>1):(n>>1)+1);

	return 0;
}