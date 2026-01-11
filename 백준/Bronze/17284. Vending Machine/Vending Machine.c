#include<stdio.h>

int main(void)
{
	int button, total=5000, price[4]={0,500,800,1000};

	while(scanf("%d", &button)!=EOF)
		total-=price[button];

	printf("%d", total);
	return 0;
}