#include<stdio.h>

int main(void)
{
	int x, y, w, h, min=1000;

	scanf("%d %d %d %d", &x, &y, &w, &h);

	min=x<min?x:min;
	min=y<min?y:min;
	min=w-x<min?w-x:min;
	min=h-y<min?h-y:min;

	printf("%d\n", min);

	return 0;
}