#include<stdio.h>

int main(void)
{
	int T, t;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &t);
		printf("O%sLINE\n", t%25<17?"N":"FF");
	}

	return 0;
}