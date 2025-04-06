#include<stdio.h>

int main(void)
{
	int A, B, C, flavor=1;

	scanf("%d%d%d", &A, &B, &C);

	if(!(A&1) && !(B&1) && !(C&1))
	{
		printf("%d", A*B*C);
		return 0;
	}

	if(A&1)
		flavor*=A;
	if(B&1)
		flavor*=B;
	if(C&1)
		flavor*=C;

	printf("%d", flavor);
	return 0;
}