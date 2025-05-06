#include<stdio.h>

int main(void)
{
	int n, h, v;

	scanf("%d%d%d", &n, &h, &v);

	h=n-h<h?h:n-h;
	v=n-v<v?v:n-v;

	printf("%d", 4*v*h);
	return 0;
}