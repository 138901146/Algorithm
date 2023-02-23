#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, *arr=NULL;
	long long int mul=0, *sum=NULL;

	scanf("%d", &N);
	arr=(int *)malloc(N*sizeof(int));
	sum=(long long int *)calloc(N,sizeof(long long int));

	for(int i=0;i<N;i++)
	{
		scanf("%d", &arr[i]);

		mul+=i>0?arr[i]*sum[i-1]:0;
		sum[i]=i>0?sum[i-1]+arr[i]:arr[i];
	}

	printf("%lld\n", mul);
	free(arr);
	free(sum);
	return 0;
}