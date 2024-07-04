#include<stdio.h>

int main(void)
{
	int R, C;

	scanf("%d", &R);
	scanf("%d", &C);

	while(R--)
	{
		for(int c=0;c<C;++c)
			printf("*");
		printf("\n");
	}

	return 0;
}