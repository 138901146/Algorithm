#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(long long *)x>*(long long *)y?1:-1;
}

int main(void)
{
	int N, M, a=0, b=0;
	long long T, *A=NULL, *B=NULL, *sum_A=NULL, *sum_B=NULL, *sum=NULL;

	scanf("%lld", &T);

	scanf("%d", &N);
	A=(long long *)malloc((N+1)*sizeof(long long));
	sum_A=(long long *)malloc(N*N*sizeof(long long));
	A[0]=0;
	for(int n=1;n<=N;++n)
	{
		scanf("%lld", &A[n]);
		A[n]+=A[n-1];
		for(int i=0;i<n;++i)
			sum_A[a++]=A[n]-A[i];
	}
	free(A);
	qsort((void *)sum_A,(size_t)a,sizeof(long long),compare);

	scanf("%d", &M);
	B=(long long *)malloc((M+1)*sizeof(long long));
	sum_B=(long long *)malloc(M*M*sizeof(long long));
	B[0]=0;
	for(int m=1;m<=M;++m)
	{
		scanf("%lld", &B[m]);
		B[m]+=B[m-1];
		for(int i=0;i<m;++i)
			sum_B[b++]=B[m]-B[i];
	}
	free(B);
	qsort((void *)sum_B,(size_t)b,sizeof(long long),compare);

	sum=(long long *)calloc(a+1,sizeof(long long));
	for(int i=0;i<a;++i)
	{
		sum[i+1]=sum[i];
		if(i>0 && sum_A[i]==sum_A[i-1])
		{
			sum[i+1]=(sum[i]<<1)-sum[i-1];
			continue;
		}

		int left=0, right=b-1, mid;

		while(left+1<right)
		{
			mid=left+right>>1;

			if(sum_A[i]+sum_B[mid]==T)
				break;
			else if(sum_A[i]+sum_B[mid]<T)
				left=mid;
			else
				right=mid;
		}

		mid=left+right>>1;
		if(sum_A[i]+sum_B[mid]==T)
		{
			++sum[i+1];
			left=mid-1;
			right=mid+1;

			while(left>=0 && sum_A[i]+sum_B[left]==T)
			{
				++sum[i+1];
				--left;
			}
			while(right<b && sum_A[i]+sum_B[right]==T)
			{
				++sum[i+1];
				++right;
			}
		}
		else if(sum_A[i]+sum_B[mid+1]==T)
		{
			++sum[i+1];
			left=mid;
			right=mid+2;

			while(left>=0 && sum_A[i]+sum_B[left]==T)
			{
				++sum[i+1];
				--left;
			}
			while(right<b && sum_A[i]+sum_B[right]==T)
			{
				++sum[i+1];
				++right;
			}
		}
	}

	printf("%lld", sum[a]);
	free(sum);
	free(sum_A);
	free(sum_B);
	return 0;
}