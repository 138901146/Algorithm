#include<stdio.h>

int main(void)
{
	int n, x;

	scanf("%d", &n);

	while(n--)
	{
		scanf("%d", &x);
		printf("%d is %s\n", x, x&1?"odd":"even");
	}

	return 0;
}