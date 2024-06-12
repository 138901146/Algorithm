#include<stdio.h>

int main(void)
{
	int a, b;

	scanf("%d%d", &a, &b);

	printf("%d", a*(100-b)/100<100);
	return 0;
}