#include<stdio.h>

int main(void)
{
	int A, B, count=0;

	scanf("%d%d", &A, &B);

	while(A<B)
	{
		if(B%2==0)
			B/=2;
		else if(B%10==1)
			B/=10;
		else
			break;
		count++;
	}

	printf("%d\n", A==B?count+1:-1);
	return 0;
}