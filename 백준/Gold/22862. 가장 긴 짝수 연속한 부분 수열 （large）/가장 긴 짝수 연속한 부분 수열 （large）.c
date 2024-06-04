#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, K, *even=NULL, S, left=0, max=0;

	scanf("%d%d", &N, &K);
	even=(int *)calloc(N+1,sizeof(int));

	for(int i=1;i<=N;++i)
	{
		scanf("%d", &S);
		even[i]=even[i-1]+(S&1);
	}

	for(int right=1;right<=N;++right)
	{
		while(left<right && K<even[right]-even[left])
			++left;

		max=right-left-even[right]+even[left]<max?max:right-left-even[right]+even[left];
	}

	printf("%d", max);
	free(even);
	return 0;
}