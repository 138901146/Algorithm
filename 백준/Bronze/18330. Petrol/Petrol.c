#include<stdio.h>

int main(void)
{
	int n, k;

	scanf("%d%d", &n, &k);

	k+=60;

	printf("%d", n<=k?n*1500:k*1500+(n-k)*3000);
	return 0;
}