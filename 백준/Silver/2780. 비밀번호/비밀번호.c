#include<stdio.h>

int main(void)
{
	int T, N, count[1001][10], sum[1001]={0, };

	for(int i=0;i<10;++i)
		count[1][i]=1;
	sum[1]=10;

	for(int n=2;n<1001;++n)
	{
		count[n][0]=count[n-1][7];
		count[n][1]=(count[n-1][2]+count[n-1][4])%1234567;
		count[n][2]=(count[n-1][1]+count[n-1][3]+count[n-1][5])%1234567;
		count[n][3]=(count[n-1][2]+count[n-1][6])%1234567;
		count[n][4]=(count[n-1][1]+count[n-1][5]+count[n-1][7])%1234567;
		count[n][5]=(count[n-1][2]+count[n-1][4]+count[n-1][6]+count[n-1][8])%1234567;
		count[n][6]=(count[n-1][3]+count[n-1][5]+count[n-1][9])%1234567;
		count[n][7]=(count[n-1][0]+count[n-1][4]+count[n-1][8])%1234567;
		count[n][8]=(count[n-1][5]+count[n-1][7]+count[n-1][9])%1234567;
		count[n][9]=(count[n-1][6]+count[n-1][8])%1234567;

		for(int i=0;i<10;++i)
			sum[n]+=count[n][i];
		sum[n]%=1234567;
	}

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &N);
		printf("%d\n", sum[N]);
	}

	return 0;
}