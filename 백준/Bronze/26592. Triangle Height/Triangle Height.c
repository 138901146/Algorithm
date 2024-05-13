#include<stdio.h>

int main(void)
{
	int n;
	double area, base;

	scanf("%d", &n);

	while(n--)
	{
		scanf("%lf%lf", &area, &base);
		printf("The height of the triangle is %.2lf units\n", area*2/base);
	}

	return 0;
}