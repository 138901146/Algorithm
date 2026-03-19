#include<stdio.h>

int main(void)
{
	float x, y;

	scanf("%f%f", &x, &y);

	while(x!=0.0||y!=0.0)
	{
		if(x==0.0||y==0.0)
			printf("AXIS\n");
		else if(0.0<x)
			printf("Q%d\n", y<0.0?4:1);
		else
			printf("Q%d\n", y<0.0?3:2);

		scanf("%f%f", &x, &y);
	}
	printf("AXIS");

	return 0;
}