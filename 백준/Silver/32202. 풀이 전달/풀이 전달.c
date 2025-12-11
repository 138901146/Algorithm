#include<stdio.h>

#define MOD 1000000007

int main(void)
{
	unsigned int N, solve[2][2]={1,2}, current=0, next=1;

	scanf("%u", &N);

	while(--N)
	{
		solve[next][0]=solve[current][1];
		solve[next][1]=(solve[current][0]+solve[current][1]<<1)%MOD;
		current^=1;
		next^=1;
	}

	printf("%u", (solve[current][0]+solve[current][1])%MOD);
	return 0;
}