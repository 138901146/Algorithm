#include<stdio.h>

int main(void)
{
	int N, min[100001]={0, };

	scanf("%d", &N);

	for(int i=0;i*i<=N;i++)
		min[i*i]=1;

	for(int i=2;i<=N;i++)
	{
		if(!min[i])
			min[i]=i;
		for(int j=1;j*j<=i;j++)
			min[i]=min[i-j*j]+1<min[i]?min[i-j*j]+1:min[i];
	}

	printf("%d\n", min[N]);
	return 0;
}