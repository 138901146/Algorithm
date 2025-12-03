#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?1:-1;
}

int main(void)
{
	int N, *a=NULL, sw=0, p=0, left=0, right;

	scanf("%d", &N);

	a=(int *)malloc(N*sizeof(int));
	for(int i=0;i<N;++i)
		scanf("%d", &a[i]);
	qsort((void *)a,(size_t)N,sizeof(int),compare);

	right=N-1;
	while(left<=right)
	{
		p+=a[left++];
		if(left<=right)
			sw+=a[right--];
	}

	printf("%d %d", sw, p);
	free(a);
	return 0;
}