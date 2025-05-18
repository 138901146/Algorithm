#include<stdio.h>

int main(void)
{
	int N, origin;
	long long total=0, mod=1;

	scanf("%d", &N);

	while(mod<=N)
		mod*=10;
	mod/=10;

	origin=N;

	do
	{
		total+=N;
		int temp=N/mod;
		N%=mod;
		N*=10;
		N+=temp;
	}
	while(N!=origin);

	printf("%lld", total);
	return 0;
}