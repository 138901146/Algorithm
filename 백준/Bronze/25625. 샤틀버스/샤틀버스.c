#include<stdio.h>

int main(void)
{
	int x, y;

	scanf("%d%d", &x, &y);

	printf("%d", y<x?x+y:y-x);
	return 0;
}