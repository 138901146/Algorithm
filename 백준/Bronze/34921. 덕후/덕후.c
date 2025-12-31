#include<stdio.h>

int main(void)
{
	int A, T, P;

	scanf("%d%d", &A, &T);

	P=10+((25-A+T)<<1);

	printf("%d", P<0?0:P);
	return 0;
}