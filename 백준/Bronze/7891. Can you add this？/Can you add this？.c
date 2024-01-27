#include<stdio.h>

int main(void)
{
	int T, x, y;

	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &x, &y);
		printf("%d\n", x+y);
	}

	return 0;
}