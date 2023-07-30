#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, X, count, max=0, *sum=NULL, visit;

	scanf("%d%d", &N, &X);
	sum=(int *)malloc((N+1)*sizeof(int));
	sum[0]=0;

	for(int n=1;n<=N;n++)
	{
		scanf("%d", &visit);
		sum[n]=sum[n-1]+visit;
	}

	for(int i=X;i<=N;i++)
		if(sum[i]-sum[i-X]>max)
		{
			count=1;
			max=sum[i]-sum[i-X];
		}
		else if(sum[i]-sum[i-X]==max)
			count++;

	if(max==0)
		printf("SAD\n");
	else
		printf("%d\n%d\n", max, count);
	free(sum);
	return 0;
}