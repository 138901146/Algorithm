#include<stdio.h>

#define INF 9999999

int main(void)
{
	int C, N, cost[20], gain[20], min[1101], fee=INF;

	min[0]=0;
	for(int i=1;i<1101;++i)
		min[i]=INF;

	scanf("%d%d", &C, &N);
	for(int n=0;n<N;++n)
		scanf("%d%d", &cost[n], &gain[n]);

	for(int c=1;c<1101;++c)
		for(int n=0;n<N;++n)
			if(0<=c-gain[n])
				min[c]=min[c]<min[c-gain[n]]+cost[n]?min[c]:min[c-gain[n]]+cost[n];

	for(int c=C;c<1101;++c)
		fee=min[c]<fee?min[c]:fee;

	printf("%d", fee);
	return 0;
}