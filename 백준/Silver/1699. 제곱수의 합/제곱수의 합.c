#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, *min=NULL;

	scanf("%d", &N);
	min=(int *)calloc(N+1,sizeof(int));

	for(int i=0;i*i<=N;i++)
		min[i*i]=1;

	for(int i=1;i<=N;i++)
	{
		if(!min[i])
			min[i]=i;
		for(int j=1;j*j<=i;j++)
			min[i]=min[i-j*j]+1<min[i]?min[i-j*j]+1:min[i];
	}

	printf("%d\n", min[N]);
	free(min);
	return 0;
}