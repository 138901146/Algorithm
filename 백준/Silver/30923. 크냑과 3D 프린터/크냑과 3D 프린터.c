#include<stdio.h>
#include<malloc.h>

int abs(int x)
{
	return x<0?-x:x;
}

int main(void)
{
	int N, *h=NULL;
	long long answer;

	scanf("%d", &N);
	h=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &h[i]);

	answer=h[0]*3+(N<<1);
	for(int i=1;i<N;++i)
		answer+=(h[i]<<1)+abs(h[i]-h[i-1]);

	printf("%lld", answer+h[N-1]);
	free(h);
	return 0;
}