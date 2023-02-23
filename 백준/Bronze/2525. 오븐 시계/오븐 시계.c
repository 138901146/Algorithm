#include<stdio.h>

int main(void)
{
	int A, B, C;

	scanf("%d %d", &A, &B);
	scanf("%d", &C);

	B+=C;

	while(B>=60)
	{
		A++;
		B-=60;
	}
	A%=24;

	printf("%d %d\n", A, B);

	return 0;
}