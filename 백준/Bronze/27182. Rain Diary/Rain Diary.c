#include<stdio.h>

int main(void)
{
	int n, m;

	scanf("%d%d", &n, &m);

	printf("%d", n<8?m+7:n-7);
	return 0;
}