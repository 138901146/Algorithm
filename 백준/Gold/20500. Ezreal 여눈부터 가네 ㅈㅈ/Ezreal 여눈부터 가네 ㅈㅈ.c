#include<stdio.h>

#define MOD 1000000007

int main(void)
{
	unsigned int N, current=1, previous=0, count[2][3]={0,0,1};

	scanf("%u", &N);

	while(--N)
	{
		for(int i=0;i<3;++i)
			count[current][i]=(count[previous][(i+1)%3]+count[previous][(i+2)%3])%MOD;

		current^=1;
		previous^=1;
	}

	printf("%u", count[previous][0]);
	return 0;
}