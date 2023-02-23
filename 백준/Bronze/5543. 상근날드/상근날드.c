#include<stdio.h>

int main(void)
{
	int minburger=2000, minbeverage=2000, price;

	for(int i=0;i<3;i++)
	{
		scanf("%d", &price);
		minburger=price<minburger?price:minburger;
	}
	for(int i=0;i<2;i++)
	{
		scanf("%d", &price);
		minbeverage=price<minbeverage?price:minbeverage;
	}

	printf("%d\n", minburger+minbeverage-50);

	return 0;
}