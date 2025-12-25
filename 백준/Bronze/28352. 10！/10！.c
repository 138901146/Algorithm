#include<stdio.h>

int main(void)
{
	int N, week=6;

	scanf("%d", &N);

	for(int n=11;n<=N;++n)
		week*=n;

	printf("%d", week);
	return 0;
}