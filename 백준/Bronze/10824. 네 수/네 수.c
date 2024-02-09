#include<stdio.h>

int main(void)
{
	long long A, B, C, D, temp;

	scanf("%lld%lld%lld%lld", &A, &B, &C, &D);

	temp=B;
	while(temp)
	{
		A*=10;
		temp/=10;
	}
	A+=B;

	temp=D;
	while(temp)
	{
		C*=10;
		temp/=10;
	}
	C+=D;

	printf("%lld", A+C);
	return 0;
}