#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, *min=NULL;

	scanf("%d", &N);
	min=(int *)calloc(N+1,sizeof(int));

	for(int i=1;i<=N;i++)
		min[i]=100000;
	for(int i=1;i*i<=N;i++)
		min[i*i]=1;

	for(int i=1;i<=N;i++)
		for(int j=1;j*j<=i;j++)
			if(min[i]>min[i-j*j]+min[j*j])
				min[i]=min[i-j*j]+min[j*j];

	printf("%d\n", min[N]);
	free(min);
	return 0;
}