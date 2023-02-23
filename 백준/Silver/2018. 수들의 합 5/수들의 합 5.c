#include<stdio.h>

int main(void)
{
	int N, count=0;

	scanf("%d", &N);

	for(int i=1;i<=N;i++)
	{
		int sum=i;

		for(int j=i+1;sum<N;j++)
			sum+=j;
		count+=sum==N;
	}

	printf("%d\n", count);
	return 0;
}