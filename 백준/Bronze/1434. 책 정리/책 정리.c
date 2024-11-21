#include<stdio.h>

int main(void)
{
	int N, M, A[50], B, sum=0, index=0;

	scanf("%d%d", &N, &M);

	for(int n=0;n<N;++n)
		scanf("%d", &A[n]);
	for(int m=0;m<M;++m)
	{
		scanf("%d", &B);

		while(A[index]<B)
			sum+=A[index++];

		A[index]-=B;
	}

	while(index<N)
		sum+=A[index++];

	printf("%d", sum);
	return 0;
}