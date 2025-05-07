#include<stdio.h>

int main(void)
{
	int N, t[2], count=0;

	scanf("%d", &N);

	if(N&1)
	{
		printf("still running");
		return 0;
	}

	for(int i=0;i<N;i+=2)
	{
		scanf("%d%d", &t[0], &t[1]);
		count+=t[1]-t[0];
	}

	printf("%d", count);
	return 0;
}