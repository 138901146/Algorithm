#include<stdio.h>

int main(void)
{
	int N, H, last=0, count=0;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d", &H);
		count+=last<=H;
		last=H;
	}

	printf("%d", count);
	return 0;
}