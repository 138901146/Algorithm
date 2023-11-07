#include<stdio.h>

int main(void)
{
	int N, x, y;

	scanf("%d%d%d", &N, &x, &y);
	--x;
	--y;

	for(int i=21;i>=0;--i)
		if((x&(1<<i))!=(y&(1<<i)))
		{
			printf("%d", i+1);
			return 0;
		}

	printf("-1");
	return 0;
}