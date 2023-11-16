#include<stdio.h>

int main(void)
{
	int N, square=0;

	scanf("%d", &N);

	while(square*square<=N)
		++square;

	printf("The largest square has side length %d.", square-1);
	return 0;
}