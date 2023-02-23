#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	long long int K, N, *lan=NULL, count=1, min=0, max=999999999999, mid;

	scanf("%lld %lld", &K, &N);
	lan=(long long int *)malloc(K*sizeof(long long int));

	for(int k=0;k<K;k++)
		scanf("%lld", &lan[k]);

	while((min+max)/2!=mid)
	{
		long long int num=0;
		mid=(min+max)/2;

		for(int k=0;k<K;k++)
			num+=lan[k]/mid;

		if(N>num)
			max=mid;
		else
			min=mid;
	}

	printf("%lld\n", mid);
	free(lan);
	return 0;
}