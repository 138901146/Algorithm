#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int N, C, *x=NULL, left=1, right=1000000000, ans=1;

	scanf("%d%d", &N, &C);
	x=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &x[i]);
	qsort((void *)x,(size_t)N,sizeof(int),compare);

	while(left<=right)
	{
		int mid=left+right>>1, last=x[0], count=1, gap=1000000000;

		for(int i=1;i<N;++i)
			if(mid<=x[i]-last)
			{
				gap=x[i]-last<gap?x[i]-last:gap;
				last=x[i];
				++count;
			}

		if(count<C)
			right=mid-1;
		else
		{
			ans=gap;
			left=mid+1;
		}
	}

	printf("%d", ans);
	free(x);
	return 0;
}