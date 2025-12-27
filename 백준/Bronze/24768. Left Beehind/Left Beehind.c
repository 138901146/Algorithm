#include<stdio.h>

int main(void)
{
	int x, y;

	scanf("%d%d", &x, &y);

	while(x||y)
	{
		if(x+y==13)
			printf("Never speak again.\n");
		else if(y<x)
			printf("To the convention.\n");
		else if(x<y)
			printf("Left beehind.\n");
		else
			printf("Undecided.\n");

		scanf("%d%d", &x, &y);
	}

	return 0;
}