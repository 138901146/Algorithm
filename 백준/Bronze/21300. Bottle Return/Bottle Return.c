#include<stdio.h>

int main(void)
{
	int bottle, sum=0;

	for(int i=0;i<6;++i)
	{
		scanf("%d", &bottle);
		sum+=bottle;
	}

	printf("%d", sum*5);
	return 0;
}