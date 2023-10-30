#include<stdio.h>

int main(void)
{
	int N, K, arr[101]={0}, sum=0, max=-100000;

	scanf("%d%d", &N, &K);
	for(int i=1;i<=N;++i)
	{
		scanf("%d", &arr[i]);
		sum+=arr[i];

		if(i>=K)
		{
			sum-=arr[i-K];
			max=sum>max?sum:max;
		}
	}

	printf("%d", max);
	return 0;
}