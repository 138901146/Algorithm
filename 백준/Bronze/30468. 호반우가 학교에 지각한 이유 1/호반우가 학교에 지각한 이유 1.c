#include<stdio.h>

int main(void)
{
	int STR, DEX, INT, LUK, N;

	scanf("%d%d%d%d%d", &STR, &DEX, &INT, &LUK, &N);

	printf("%d", (N<<2)-STR-DEX-INT-LUK<0?0:(N<<2)-STR-DEX-INT-LUK);
	return 0;
}