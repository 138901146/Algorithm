#include<stdio.h>

int main(void)
{
	int connected[501]={0, }, N, current=0, a, b, sorted[500], LIS[501], max=1;

	scanf("%d", &N);

	for(int n=0;n<N;n++)
	{
		scanf("%d%d", &a, &b);
		connected[a]=b;
	}

	for(int i=0;i<501;i++)
		if(connected[i])
			sorted[current++]=connected[i];

	for(int i=0;i<N;i++)
	{
		LIS[i]=1;
		for(int j=0;j<i;j++)
			if(sorted[i]>sorted[j] && LIS[i]<LIS[j]+1)
			{
				LIS[i]=LIS[j]+1;
				max=LIS[i]>max?LIS[i]:max;
			}
	}

	printf("%d\n", N-max);
	return 0;
}