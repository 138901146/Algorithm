#include<stdio.h>

int main(void)
{
	int N, A[1000], sum[1000]={0}, max=0;

	scanf("%d", &N);

	for(int i=0;i<N;++i)
	{
		scanf("%d", &A[i]);

		for(int j=0;j<i;++j)
			if(A[i]<A[j] && sum[i]<sum[j])
				sum[i]=sum[j];

		sum[i]+=A[i];
		max=sum[i]<max?max:sum[i];
	}

	printf("%d", max);
	return 0;
}