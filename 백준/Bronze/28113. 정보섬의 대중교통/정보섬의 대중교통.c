#include<stdio.h>

int main(void)
{
	int N, A, B;

	scanf("%d%d%d", &N, &A, &B);

	printf("%s", A<B?"Bus":B<A?"Subway":"Anything");
	return 0;
}