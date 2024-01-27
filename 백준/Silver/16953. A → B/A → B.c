#include<stdio.h>

int main(void)
{
	int A, B, count=0;

	scanf("%d%d", &A, &B);

	while(A<B)
	{
		if(!(B&1))
			B>>=1;
		else if(B%10==1)
			B/=10;
		else
			break;
		++count;
	}

	printf("%d", A==B?count+1:-1);
	return 0;
}