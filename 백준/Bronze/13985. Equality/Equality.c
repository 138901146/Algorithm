#include<stdio.h>

int main(void)
{
	int a, b, c;

	scanf("%d + %d = %d", &a, &b, &c);

	printf("%s", a+b==c?"YES":"NO");
	return 0;
}