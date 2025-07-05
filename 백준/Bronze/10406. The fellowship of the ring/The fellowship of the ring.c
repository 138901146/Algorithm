#include<stdio.h>

int main(void)
{
	int W, N, P, H, count=0;

	scanf("%d%d%d", &W, &N, &P);

	while(P--)
	{
		scanf("%d", &H);
		count+=W<=H&&H<=N;
	}

	printf("%d", count);
	return 0;
}