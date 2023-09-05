#include<stdio.h>

int main(void)
{
	int N, A[1000], min[1000];

	scanf("%d", &N);

	for(int i=0;i<N;++i)
	{
		min[i]=10000;
		scanf("%d", &A[i]);
	}

	min[0]=0;
	for(int i=0;i<N;++i)
		for(int j=1;j<=A[i] && i+j<N;++j)
			min[i+j]=min[i+j]>min[i]+1?min[i]+1:min[i+j];

	printf("%d", min[N-1]==10000?-1:min[N-1]);
	return 0;
}