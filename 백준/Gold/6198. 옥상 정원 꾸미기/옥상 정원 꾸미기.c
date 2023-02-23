#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, *h=NULL, *bigger=NULL;
	long long sum=0;

	scanf("%d", &N);
	h=(int *)malloc(N*sizeof(int));
	bigger=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;n++)
		scanf("%d", &h[n]);

	bigger[N-1]=N;
	for(int n=N-2;n>=0;n--)
	{
		int next_bigger=n+1;

		while(next_bigger<N && h[next_bigger]<h[n])
			next_bigger=bigger[next_bigger];

		bigger[n]=next_bigger;
		sum+=bigger[n]-n-1;
	}

	printf("%lld\n", sum);
	free(bigger);
	free(h);
	return 0;
}