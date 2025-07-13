#include<stdio.h>

int main(void)
{
	int N, n, count[1001]={0}, max=0;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d", &n);
		++count[n];
	}

	for(int i=1;i<1001;++i)
		max=count[i]<max?max:count[i];

	printf("%d", max);
	return 0;
}