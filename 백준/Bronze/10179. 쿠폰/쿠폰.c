#include<stdio.h>

int main(void)
{
	int T;
	double price;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		scanf("%lf", &price);

		price*=0.8;
		price*=1000;
		if((int)price%10>4)
			price+=10;
		price/=1000;

		printf("$%.2lf\n", price);
	}

	return 0;
}