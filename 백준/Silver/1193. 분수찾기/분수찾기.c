#include<stdio.h>

int main(void)
{
	int X, n=1, i;

	scanf("%d", &X);

	while(((n*(n+1))/2)<X)
		n++;
	i=(n*(n+1))/2-X;

	printf("%d/%d", n%2==0?n-i:i+1, n%2==0?i+1:n-i);

	return 0;
}