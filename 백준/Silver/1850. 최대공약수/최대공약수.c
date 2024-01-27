#include<stdio.h>

int main(void)
{
	long long A, B, temp;

	scanf("%lld%lld", &A, &B);

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

	while(A--)
		printf("1");
	return 0;
}