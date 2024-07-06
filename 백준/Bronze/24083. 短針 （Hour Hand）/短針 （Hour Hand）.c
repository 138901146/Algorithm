#include<stdio.h>

int main(void)
{
	int A, B;

	scanf("%d", &A);
	scanf("%d", &B);

	printf("%d", (A+B-1)%12+1);
	return 0;
}