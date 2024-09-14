#include<stdio.h>

int main(void)
{
	int A, B;

	scanf("%d%d", &A, &B);

	--A;
	A=A<B?A:B;

	printf("%d", A<<1|1);
	return 0;
}