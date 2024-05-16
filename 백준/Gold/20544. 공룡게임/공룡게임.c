#include<stdio.h>

#define MOD 1000000007

int main(void)
{
	int N;
	long long map[1001][12]={0};

	scanf("%d", &N);

	map[1][0]=1;
	for(int n=2;n<=N;++n)
	{
		map[n][0]=map[n][1]=(map[n-1][0]+map[n-1][2])%MOD;
		map[n][2]=(map[n-1][1]+map[n-1][3])%MOD;
		map[n][3]=map[n-1][1];
		map[n][4]=map[n][5]=(map[n-1][4]+map[n-1][7]+map[n-1][10])%MOD;
		map[n][6]=(map[n][0]+map[n][4])%MOD;
		map[n][7]=(map[n-1][5]+map[n-1][8]+map[n-1][11])%MOD;
		map[n][8]=map[n-1][5];
		map[n][9]=(map[n-1][1]+map[n-1][5])%MOD;
		map[n][10]=(map[n-1][6]+map[n-1][9])%MOD;
		map[n][11]=map[n-1][6];
	}

	printf("%lld", (map[N][4]+map[N][5]+map[N][6]+map[N][7]+map[N][8]+map[N][9]+map[N][10]+map[N][11])%MOD);
	return 0;
}