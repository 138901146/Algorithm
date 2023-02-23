#include<stdio.h>

int main(void)
{
	long int N, M;

	scanf("%ld %ld", &N, &M);

	N-=M;
	if(N<0)
		N=-N;

	printf("%ld\n", N);
	return 0;
}