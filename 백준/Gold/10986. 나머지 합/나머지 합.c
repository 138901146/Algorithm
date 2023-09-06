#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, M, current=0;
	long long sum[2]={0,0}, *left=NULL, count=0;

	scanf("%d%d", &N, &M);
	left=(long long *)calloc(M,sizeof(long long));

	left[0]=1;

	while(N--)
	{
		scanf("%lld", &sum[current]);
		sum[current]+=sum[current^1];
		count+=left[sum[current]%M]++;
		current^=1;
	}

	printf("%lld", count);
	free(left);
	return 0;
}