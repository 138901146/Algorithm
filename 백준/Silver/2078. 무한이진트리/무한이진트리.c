#include<stdio.h>

int main(void)
{
	int A, B, left=0, right=0;

	scanf("%d%d", &A, &B);

	while(1<A || 1<B)
		if(A==1)
		{
			right+=B-1;
			B=1;
		}
		else if(B==1)
		{
			left+=A-1;
			A=1;
		}
		else if(A<B)
		{
			++right;
			B-=A;
		}
		else
		{
			++left;
			A-=B;
		}

	printf("%d %d", left, right);
	return 0;
}