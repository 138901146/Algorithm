#include<stdio.h>

int main(void)
{
	int T, x, y;

	scanf("%d", &T);
	for(int t=0;t<T;t++)
	{
		scanf("%d%d", &x, &y);
		printf("%d\n", x+y);
	}

	return 0;
}