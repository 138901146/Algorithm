#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int N, M, *armor=NULL, left=0, right, count=0;

	scanf("%d", &N);
	scanf("%d", &M);
	armor=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;++n)
		scanf("%d", &armor[n]);

	qsort((void *)armor,(size_t)N,sizeof(int),compare);
	right=N-1;

	while(left<right)
		if(armor[left]+armor[right]==M)
		{
			++count;
			++left;
			--right;
		}
		else if(armor[left]+armor[right]<M)
			++left;
		else
			--right;


	printf("%d", count);
	free(armor);
	return 0;
}