#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int N, M, *a=NULL, *b=NULL;
	long long HI=0, ARC=0, draw=0;

	scanf("%d%d", &N, &M);
	a=(int *)malloc(N*sizeof(int));
	b=(int *)malloc(M*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &a[i]);
	for(int i=0;i<M;++i)
		scanf("%d", &b[i]);

	qsort((void *)a,(size_t)N,sizeof(int),compare);
	qsort((void *)b,(size_t)M,sizeof(int),compare);

	for(int hi=0;hi<N;++hi)
	{
		int left=0, right=M-1, mid, point=0, win, lose;

		while(left<=right)
		{
			mid=left+right>>1;

			if(b[mid]<a[hi])
			{
				left=mid+1;
				point=mid;
			}
			else
				right=mid-1;
		}

		win=point+(b[point]<a[hi]);
		left=0;
		right=point=M-1;

		while(left<=right)
		{
			mid=left+right>>1;

			if(a[hi]<b[mid])
			{
				right=mid-1;
				point=mid;
			}
			else
				left=mid+1;
		}

		lose=M-point-(b[point]<=a[hi]);

		HI+=win;
		ARC+=lose;
		draw+=M-win-lose;
	}

	printf("%lld %lld %lld", HI, ARC, draw);
	free(a);
	free(b);
	return 0;
}