#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, M, seat[41][3]={0}, vip;
	bool is_vip[41]={false};

	scanf("%d", &N);
	scanf("%d", &M);

	while(M--)
	{
		scanf("%d", &vip);
		is_vip[vip]=true;
	}

	seat[1][1]=1;
	seat[1][2]=!is_vip[1];
	for(int n=2;n<=N;++n)
	{
		seat[n][1]=seat[n-1][0]+seat[n-1][1];
		if(!is_vip[n])
		{
			seat[n][0]=seat[n-1][2];
			seat[n][2]=seat[n-1][0]+seat[n-1][1];
		}
	}

	printf("%d", seat[N][0]+seat[N][1]);
	return 0;
}