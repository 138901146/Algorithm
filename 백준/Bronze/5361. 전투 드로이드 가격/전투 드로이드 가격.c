#include<stdio.h>

int main(void)
{
	float price[5]={350.34, 230.9, 190.55, 125.3, 180.9};
	int T;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		int need;
		float total=0.0;

		for(int i=0;i<5;i++)
		{
			scanf("%d", &need);
			total+=price[i]*need;
		}

		printf("$%.2f\n", total);
	}

	return 0;
}