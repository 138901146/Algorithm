#include<stdio.h>

int main(void)
{
	int N, stair, max[303][2]={0, };

	scanf("%d", &N);
	for(int n=1;n<=N;n++)
	{
		scanf("%d", &stair);
		int local=max[n][0]>max[n][1]?max[n][0]:max[n][1];
		max[n+2][0]=stair+local>max[n+2][0]?stair+local:max[n+2][0];
		max[n+1][1]=stair+max[n][0]>max[n+1][1]?stair+max[n][0]:max[n+1][1];
	}

	printf("%d\n", max[N][0]<max[N][1]?stair+max[N][1]:stair+max[N][0]);
	return 0;
}