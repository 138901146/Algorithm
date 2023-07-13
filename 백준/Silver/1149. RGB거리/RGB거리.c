#include<stdio.h>

int main(void)
{
	int N, color[1000][3], min[1000][3], cheap=1000000000;

	scanf("%d", &N);

	for(int i=0;i<3;i++)
	{
		scanf("%d", &color[0][i]);
		min[0][i]=color[0][i];
	}
	for(int n=1;n<N;n++)
		for(int i=0;i<3;i++)
		{
			scanf("%d", &color[n][i]);
			min[n][i]=1000000000;
			for(int j=1;j<3;j++)
				min[n][i]=min[n-1][(i+j)%3]+color[n][i]<min[n][i]?min[n-1][(i+j)%3]+color[n][i]:min[n][i];
		}

	for(int i=0;i<3;i++)
		cheap=min[N-1][i]<cheap?min[N-1][i]:cheap;

	printf("%d\n", cheap);
	return 0;
}