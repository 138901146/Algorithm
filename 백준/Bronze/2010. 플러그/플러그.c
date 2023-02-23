#include<stdio.h>

int main(void)
{
	int N, sum=1, plug;

	scanf("%d", &N);

	for(int n=0;n<N;n++)
	{
		scanf("%d", &plug);
		sum+=plug-1;
	}

	printf("%d\n", sum);
	return 0;
}