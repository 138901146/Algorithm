#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int N, K, *w=NULL, left=0, right, count=0;

	scanf("%d%d", &N, &K);
	w=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &w[i]);
	qsort((void *)w,(size_t)N,sizeof(int),compare);

	right=N-1;
	while(left<right)
	{
		while(left<right&&K<w[left]+w[right])
			--right;

		if(left<right)
		{
			++count;
			++left;
			--right;
		}
		else
			break;
	}

	printf("%d", count);
	free(w);
	return 0;
}