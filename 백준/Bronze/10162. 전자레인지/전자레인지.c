#include<stdio.h>

int main(void)
{
	int A, B, T;

	scanf("%d", &T);

	A=T/300;
	T%=300;
	B=T/60;
	T%=60;
	if(T%10==0)
		printf("%d %d %d\n", A, B, T/10);
	else
		printf("-1\n");

	return 0;
}