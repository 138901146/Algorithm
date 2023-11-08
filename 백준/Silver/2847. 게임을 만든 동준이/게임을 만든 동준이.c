#include<stdio.h>

int main(void)
{
	int N, level[100], sum=0;

	scanf("%d", &N);

	for(int n=0;n<N;++n)
		scanf("%d", &level[n]);

	for(int n=N-2;n>=0;--n)
		if(level[n]>=level[n+1])
		{
			sum+=level[n]-(level[n+1]-1);
			level[n]=level[n+1]-1;
		}

	printf("%d", sum);
	return 0;
}