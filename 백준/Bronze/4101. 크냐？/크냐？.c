#include<stdio.h>

int main(void)
{
	int x, y;

	scanf("%d %d", &x, &y);

	while(x!=0 || y!=0)
	{
		printf("%s\n", x>y?"Yes":"No");

		scanf("%d %d", &x, &y);
	}

	return 0;
}