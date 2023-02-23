#include<stdio.h>

int main(void)
{
	unsigned long long int A, B, lcm;

	scanf("%llu %llu", &A, &B);
	if(A<B)
	{
		lcm=A;
		A=B;
		B=lcm;
	}
	lcm=A;

	while(lcm%B!=0)
		lcm+=A;

	printf("%llu\n", lcm);
	return 0;
}