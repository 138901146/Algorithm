#include<stdio.h>

int main(void)
{
	int N, K, *temperature=NULL, sum=0, max=-1000000000;

	scanf("%d%d", &N, &K);
	temperature=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;n++)
		scanf("%d", &temperature[n]);

	for(int k=0;k<K;k++)
		sum+=temperature[k];
	max=sum;
	for(int k=K;k<N;k++)
	{
		sum=sum-temperature[k-K]+temperature[k];
		max=sum>max?sum:max;
	}

	printf("%d\n", max);
	free(temperature);
	return 0;
}