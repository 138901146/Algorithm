#include<stdio.h>

int main(void)
{
	int A, B;

	scanf("%d", &A);
	scanf("%d", &B);
	printf("%d\n%d\n%d\n%d", A*(B%10), A*((B/10)%10), A*(B/100), A*B);

	return 0;
}