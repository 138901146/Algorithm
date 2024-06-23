#include<stdio.h>

int main(void)
{
	int A, B;

	scanf("%d", &A);
	scanf("%d", &B);

	printf("%d", A<B?-1:A>B?1:0);
	return 0;
}