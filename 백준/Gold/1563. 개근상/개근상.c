#include<stdio.h>

#define MOD 1000000

int main(void)
{
	int N, count[2][4][2]={1,0,}, current=1, previous=0, sum=0;

	scanf("%d", &N);

	while(N--)
	{
		count[current][0][0]=(count[previous][0][0]+count[previous][2][0]+count[previous][3][0])%MOD;
		count[current][0][1]=(count[previous][0][1]+count[previous][1][1]+count[previous][2][1]+count[previous][3][1])%MOD;
		count[current][1][1]=(count[previous][0][0]+count[previous][2][0]+count[previous][3][0])%MOD;
		count[current][2][0]=count[previous][0][0];
		count[current][2][1]=(count[previous][0][1]+count[previous][1][1])%MOD;
		count[current][3][0]=count[previous][2][0];
		count[current][3][1]=count[previous][2][1];

		current^=1;
		previous^=1;
	}

	for(int i=0;i<4;++i)
		for(int j=0;j<2;++j)
			sum+=count[previous][i][j];

	printf("%d", sum%MOD);
	return 0;
}