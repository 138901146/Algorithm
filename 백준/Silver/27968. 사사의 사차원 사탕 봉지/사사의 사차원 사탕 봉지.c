#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, M;
	long long *A=NULL, *B=NULL;

	scanf("%d%d", &N, &M);

	A=(long long *)calloc(M+1,sizeof(long long));
	B=(long long *)malloc(N*sizeof(long long));

	for(int m=1;m<=M;++m)
	{
		scanf("%lld", &A[m]);
		A[m]+=A[m-1];
	}

	for(int n=0;n<N;++n)
		scanf("%lld", &B[n]);

	for(int n=0;n<N;++n)
	{
		int left=1, right=M;
		long long b=B[n];

		B[n]=M;

		while(left<=right)
		{
			int mid=left+right>>1;

			if(A[mid]<b)
				left=mid+1;
			else
			{
				right=mid-1;
				B[n]=mid;
			}
		}

		if(A[B[n]]<b)
			B[n]=-1;
	}

	for(int n=0;n<N;++n)
		if(B[n]==-1)
			printf("Go away!\n");
		else
			printf("%lld\n", B[n]);
	free(A);
	free(B);
	return 0;
}