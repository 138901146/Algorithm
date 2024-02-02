#include<stdio.h>

int main(void)
{
	long long A, B, mul, temp;

	scanf("%lld%lld", &A, &B);

	mul=A*B;
	while(B)
	{
		temp=A%B;
		A=B;
		B=temp;
	}

	printf("%lld", mul/A);
}