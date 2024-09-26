#include<stdio.h>

int main(void)
{
	int W, length=2;

	scanf("%d", &W);

	W<<=1;

	while(length*length!=W)
		++length;

	printf("%d", length<<2);
	return 0;
}