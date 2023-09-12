#include<stdio.h>

int abs(int x)
{
	return x<0?-x:x;
}

int main(void)
{
	int N, x[3], y[3], direct[2], pass, sum, max=0;

	scanf("%d", &N);

	scanf("%d%d", &x[0], &y[0]);
	scanf("%d%d", &x[1], &y[1]);
	sum=direct[1]=abs(x[1]-x[0])+abs(y[1]-y[0]);
	for(int i=2;i<N;++i)
	{
		scanf("%d%d", &x[i%3], &y[i%3]);
		direct[i&1]=abs(x[i%3]-x[(i-1)%3])+abs(y[i%3]-y[(i-1)%3]);
		pass=abs(x[i%3]-x[(i-2)%3])+abs(y[i%3]-y[(i-2)%3]);
		sum+=direct[i&1];
		max=direct[0]+direct[1]-pass>max?direct[0]+direct[1]-pass:max;
	}

	printf("%d", sum-max);
	return 0;
}