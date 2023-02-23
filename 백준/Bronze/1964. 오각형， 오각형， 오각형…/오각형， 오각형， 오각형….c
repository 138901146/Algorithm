#include<stdio.h>

int main(void)
{
	unsigned long long int dot=5;
	int N, plus=7;

	scanf("%d", &N);

	for(int i=1;i<N;i++,plus+=3)
		dot+=plus;

	printf("%llu\n", dot%45678);
	return 0;
}