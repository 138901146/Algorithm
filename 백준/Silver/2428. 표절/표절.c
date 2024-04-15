#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int N, *F=NULL;
	long long evaluate=0;

	scanf("%d", &N);
	F=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;++n)
		scanf("%d", &F[n]);
	qsort((void *)F,(size_t)N,sizeof(int),compare);

	for(int n=1;n<N;++n)
	{
		int left=0, right=n, mid, value=n;

		while(left<=right)
		{
			mid=left+right>>1;

			if(F[n]*9<=F[mid]*10)
			{
				value=mid;
				right=mid-1;
			}
			else
				left=mid+1;
		}

		evaluate+=n-value;
	}

	printf("%lld", evaluate);
	free(F);
	return 0;
}