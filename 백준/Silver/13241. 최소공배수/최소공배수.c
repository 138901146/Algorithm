#include<stdio.h>

int main(void)
{
	long long A, B, mul, temp;

	scanf("%lld%lld", &A, &B);

	mul=A*B;
	if(A<B)
	{
		temp=A;
		A=B;
		B=temp;
	}

	while(B)
	{
		temp=A%B;
		A=B;
		B=temp;
	}

	printf("%lld", mul/A);
}