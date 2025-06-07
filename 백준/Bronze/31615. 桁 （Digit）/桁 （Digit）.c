#include<stdio.h>

int main(void)
{
	int A, B, count=0;

	scanf("%d", &A);
	scanf("%d", &B);

	A+=B;

	while(A)
	{
		++count;
		A/=10;
	}

	printf("%d", count);
	return 0;
}