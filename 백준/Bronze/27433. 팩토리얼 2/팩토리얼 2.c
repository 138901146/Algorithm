#include<stdio.h>

int main(void)
{
	int N;
	unsigned long long factorial=1;

	scanf("%d", &N);

	for(int n=1;n<=N;n++)
		factorial*=n;

	printf("%llu\n", factorial);
	return 0;
}