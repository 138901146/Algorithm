#include<stdio.h>

int main(void)
{
	int X, Y, N, x, y;

	scanf("%d%d", &X, &Y);
	scanf("%d", &N);

	while(N--)
	{
		scanf("%d%d", &x, &y);
		printf("%d\n", x!=X&&y!=Y);
	}

	return 0;
}