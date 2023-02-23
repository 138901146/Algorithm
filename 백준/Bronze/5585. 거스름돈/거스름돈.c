#include<stdio.h>

int main(void)
{
	int price, count=0;

	scanf("%d", &price);
	price=1000-price;

	while(price>=500)
	{
		price-=500;
		count++;
	}
	while(price>=100)
	{
		price-=100;
		count++;
	}
	while(price>=50)
	{
		price-=50;
		count++;
	}
	while(price>=10)
	{
		price-=10;
		count++;
	}
	while(price>=5)
	{
		price-=5;
		count++;
	}

	printf("%d\n", count+price);

	return 0;
}