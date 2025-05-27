#include<stdio.h>

int N, K, A[8], full, count=0;

void simulate(int current,int done)
{
	if(current<500)
		return;
	else if(done==full)
		++count;
	else
		for(int n=0;n<N;++n)
			if(!(done&(1<<n)))
				simulate(current+A[n]-K,1<<n|done);
}

int main(void)
{
	scanf("%d%d", &N, &K);
	for(int n=0;n<N;++n)
		scanf("%d", &A[n]);

	full=(1<<N)-1;

	simulate(500,0);

	printf("%d", count);
	return 0;
}