#include<stdio.h>

int main(void)
{
	int M, N, sum=0, min=10000;

	scanf("%d", &M);
	scanf("%d", &N);

	for(int i=1;i*i<=N;i++)
		if(i*i>=M)
		{
			sum+=i*i;
			min=i*i<min?i*i:min;
		}

	if(sum==0)
		printf("-1\n");
	else
		printf("%d\n%d\n", sum, min);

	return 0;
}