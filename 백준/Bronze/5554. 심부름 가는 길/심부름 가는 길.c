#include<stdio.h>

int main(void)
{
	int x, y=0;

	for(int i=0;i<4;i++)
	{
		scanf("%d", &x);

		y+=x;
	}

	printf("%d\n%d\n", y/60, y%60);

	return 0;
}