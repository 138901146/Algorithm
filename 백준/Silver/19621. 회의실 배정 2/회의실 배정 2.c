#include<stdio.h>

int main(void)
{
	int N, start, end, count[25], max[25][2]={0};

	scanf("%d", &N);

	for(int i=0;i<N;++i)
		scanf("%d%d%d", &start, &end, &count[i]);

	max[0][1]=count[0];
	for(int i=1;i<N;++i)
	{
		max[i][0]=max[i-1][0]<max[i-1][1]?max[i-1][1]:max[i-1][0];
		max[i][1]=max[i-1][0]+count[i];
	}

	printf("%d", max[N-1][0]<max[N-1][1]?max[N-1][1]:max[N-1][0]);
	return 0;
}