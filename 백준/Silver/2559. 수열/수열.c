#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, K, *temperature=NULL, sum=0, max;

	scanf("%d%d", &N, &K);
	temperature=(int *)malloc(K*sizeof(int));

	for(int k=0;k<K;++k)
	{
		scanf("%d", &temperature[k]);
		sum+=temperature[k];
	}

	max=sum;
	for(int i=K;i<N;++i)
	{
		int index=i%K;

		sum-=temperature[index];
		scanf("%d", &temperature[index]);
		sum+=temperature[index];

		max=max<sum?sum:max;
	}

	printf("%d", max);
	free(temperature);
	return 0;
}