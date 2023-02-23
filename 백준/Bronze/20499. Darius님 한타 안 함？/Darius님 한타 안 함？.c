#include<stdio.h>

int main(void)
{
	int K, D, A;

	scanf("%d/%d/%d", &K, &D, &A);

	printf("%s\n", K+A<D||D==0?"hasu":"gosu");
	return 0;
}