#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, *A=NULL, sum[11]={0}, left=0, max=0;

	scanf("%d", &N);
	A=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &A[i]);

	for(int right=0;right<N;++right)
	{
		int lm=10, rm=0;

		++sum[A[right]];

		for(int i=1;i<11;++i)
			rm=sum[i]?i:rm;
		for(int i=10;0<i;--i)
			lm=sum[i]?i:lm;

		while(left<right&&2<rm-lm)
		{
			--sum[A[left++]];
			lm=10;
			rm=0;
			for(int i=1;i<11;++i)
				rm=sum[i]?i:rm;
			for(int i=10;0<i;--i)
				lm=sum[i]?i:lm;
		}

		max=right-left+1<max?max:right-left+1;
	}

	printf("%d", max);
	free(A);
	return 0;
}