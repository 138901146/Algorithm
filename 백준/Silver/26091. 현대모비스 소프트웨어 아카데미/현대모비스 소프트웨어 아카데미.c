#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int N, M, *a=NULL, left=0, right, count=0;

	scanf("%d%d", &N, &M);
	a=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;++n)
		scanf("%d", &a[n]);
	qsort((void *)a,(size_t)N,sizeof(int),compare);

	right=N-1;
	while(left<right)
	{
		while(left<right&&a[left]+a[right]<M)
			++left;

		if(left!=right)
		{
			++count;
			++left;
			--right;
		}
	}

	printf("%d", count);
	free(a);
	return 0;
}