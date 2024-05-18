#include<stdio.h>

int main(void)
{
	int N, *a=NULL, max, *min=NULL, best=0;

	scanf("%d", &N);
	a=(int *)malloc((N+1)*sizeof(int));
	min=(int *)malloc((N+1)*sizeof(int));

	min[0]=2000000000;
	for(int i=1;i<=N;++i)
	{
		scanf("%d", &a[i]);
		min[i]=min[i-1]<a[i]?min[i-1]:a[i];
	}

	max=a[N];
	for(int i=N-1;i;--i)
	{
		max=max<a[i]?a[i]:max;
		best=best<max-min[i]?max-min[i]:best;
	}

	printf("%d", best);
	free(a);
	free(min);
	return 0;
}