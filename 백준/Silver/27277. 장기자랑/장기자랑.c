#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int N, *a=NULL, left=0, right, count;

	scanf("%d", &N);
	a=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &a[i]);
	qsort((void *)a,(size_t)N,sizeof(int),compare);

	count=a[N-1];
	right=N-2;
	while(left<right)
		count+=a[right--]-a[left++];

	printf("%d", count);
	free(a);
	return 0;
}