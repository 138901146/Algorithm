#include<stdio.h>

int main(void)
{
	int A, B, V;

	scanf("%d %d %d", &A, &B, &V);

	printf("%d\n", V<A?1:(V-A)%(A-B)==0?(V-A)/(A-B)+1:(V-A)/(A-B)+2);

	return 0;
}