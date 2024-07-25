#include<stdio.h>

int main(void)
{
	int H, W;

	scanf("%d", &H);
	scanf("%d", &W);

	H*=50;
	W*=50;

	printf("%d", H<W?H:W);
	return 0;
}