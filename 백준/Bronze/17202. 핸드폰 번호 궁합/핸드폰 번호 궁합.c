#include<stdio.h>

int main(void)
{
	int number[16][2], current=0, next=1, total=16;

	for(int i=0;i<8;++i)
		scanf("%1d", &number[i<<1][0]);
	for(int i=0;i<8;++i)
		scanf("%1d", &number[i<<1|1][0]);

	while(2<total)
	{
		for(int i=1;i<total;++i)
			number[i-1][next]=(number[i-1][current]+number[i][current])%10;

		--total;
		current^=1;
		next^=1;
	}

	printf("%d%d", number[0][current], number[1][current]);
	return 0;
}