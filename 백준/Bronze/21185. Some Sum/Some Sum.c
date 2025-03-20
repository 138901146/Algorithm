#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	printf("%s", N&1?"Either":N%4?"Odd":"Even");
	return 0;
}