#include<stdio.h>

int main(void)
{
	int R, S;

	scanf("%d", &R);
	scanf("%d", &S);

	printf("%d", (R<<3)+S*3-28);
	return 0;
}