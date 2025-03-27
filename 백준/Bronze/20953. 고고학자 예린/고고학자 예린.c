#include<stdio.h>

int main(void)
{
	int T, a, b;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d%d", &a, &b);
		a+=b;
		printf("%d\n", (a*(a-1)>>1)*a);
	}

	return 0;
}