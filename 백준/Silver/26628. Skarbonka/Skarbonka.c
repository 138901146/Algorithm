#include<stdio.h>

int count[300000]={0};

int main(void)
{
	int n, a, best=0;

	scanf("%d", &n);

	while(n--)
	{
		scanf("%d", &a);
		++count[a];
	}

	for(int i=1;i<300000;++i)
	{
		count[i]+=count[i-1]>>1;
		best=count[i]?i:best;
	}

	printf("%d", best);
	return 0;
}