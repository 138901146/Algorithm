#include<stdio.h>

long long mul(int A,int B,int C)
{
	if(B==1)
		return A%C;

	long long root=mul(A,B>>1,C)%C;

	return root*root%C*(B&1?A:1)%C;
}

int main(void)
{
	int A, B, C;

	scanf("%d%d%d", &A, &B, &C);

	printf("%lld", mul(A,B,C));
	return 0;
}