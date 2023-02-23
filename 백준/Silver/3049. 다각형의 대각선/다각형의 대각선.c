#include<stdio.h>

int main(void)
{
	int N, diagonal=1;

	scanf("%d", &N);

	for(int i=0;i<4;i++)
		diagonal*=(N-i);
	diagonal/=24;

	printf("%d\n", diagonal);
	return 0;
}