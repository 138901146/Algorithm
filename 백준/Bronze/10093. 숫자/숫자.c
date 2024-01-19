#include<stdio.h>

int main(void)
{
	long long A, B;

	scanf("%lld%lld", &A, &B);

	if(A>B)
	{
		long long temp=A;
		A=B;
		B=temp;
	}

	printf("%lld\n", B-1-A<0?0:B-1-A);
	for(long long C=A+1;C<B;++C)
		printf("%lld ", C);

	return 0;
}