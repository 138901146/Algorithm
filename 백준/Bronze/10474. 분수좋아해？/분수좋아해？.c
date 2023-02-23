#include<stdio.h>

int main(void)
{
	int numerator, denominator;

	scanf("%d %d", &numerator, &denominator);

	while(numerator!=0 || denominator!=0)
	{
		printf("%d %d / %d\n", numerator/denominator, numerator%denominator, denominator);
		scanf("%d %d", &numerator, &denominator);
	}

	return 0;
}