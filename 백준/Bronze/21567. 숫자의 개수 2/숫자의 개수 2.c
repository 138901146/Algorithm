#include<stdio.h>

int main(void)
{
	int A, B, C, digit[10]={0};
	long long mul;

	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);

	mul=(long long)A*B*C;

	while(mul)
	{
		++digit[mul%10];
		mul/=10;
	}

	for(int i=0;i<10;++i)
		printf("%d\n", digit[i]);

	return 0;
}