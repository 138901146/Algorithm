#include<stdio.h>

int main(void)
{
	int N, H, d, count=0;

	scanf("%d%d", &N, &H);

	while(0<H && N--)
	{
		scanf("%d", &d);
		H-=d;
		++count;
	}

	printf("%d", 0<H?-1:count);
	return 0;
}