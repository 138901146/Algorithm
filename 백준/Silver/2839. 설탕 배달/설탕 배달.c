#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	printf("%d\n", N==4||N==7?-1:3*(N/15)+N%15%2+2*((N%15>5&&N%15%2==1)+(N%15>0&&N%15%2==0)+(N%15>10&&N%15%2==0)));

	return 0;
}