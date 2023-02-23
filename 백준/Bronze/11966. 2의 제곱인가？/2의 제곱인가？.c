#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	while(N>1 && N%2==0)
		N/=2;

	printf("%d\n", N==1);
	return 0;
}