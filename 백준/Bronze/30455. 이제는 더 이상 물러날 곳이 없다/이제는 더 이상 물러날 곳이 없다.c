#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	printf("%s", N&1?"Goose":"Duck");
	return 0;
}