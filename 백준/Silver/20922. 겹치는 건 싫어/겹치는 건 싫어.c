#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, K, *a=NULL, *count=NULL, max=0, left=0, right=0;

	scanf("%d%d", &N, &K);
	a=(int *)malloc(N*sizeof(int));
	count=(int *)calloc(100001,sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &a[i]);

	while(right<N)
	{
		while(left<right&&K<=count[a[right]])
			--count[a[left++]];
		++count[a[right++]];
		max=right-left<max?max:right-left;
	}

	printf("%d", max);
	free(a);
	free(count);
	return 0;
}