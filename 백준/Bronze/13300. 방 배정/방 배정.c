#include<stdio.h>

int main(void)
{
	int N, K, S, Y, total[2][6]={0, }, room=0;

	scanf("%d %d", &N, &K);

	for(int n=0;n<N;n++)
	{
		scanf("%d %d", &S, &Y);
		total[S][Y-1]++;
	}

	for(int i=0;i<6;i++)
		for(int j=0;j<2;j++)
			room+=total[j][i]/K+(total[j][i]%K!=0);

	printf("%d\n", room);
	return 0;
}