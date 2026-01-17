#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	printf("%s", N<10001?"Accepted":"Time limit exceeded");
	return 0;
}