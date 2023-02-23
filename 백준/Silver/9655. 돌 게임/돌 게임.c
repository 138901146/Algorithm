#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	printf("%s\n", N%2==1?"SK":"CY");

	return 0;
}