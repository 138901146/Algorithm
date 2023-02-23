#include<stdio.h>

int main(void)
{
	int N, sum=0, number;

	scanf("%d", &N);
	for(int i=0;i<N;i++)
	{
		scanf("%1d", &number);
		sum+=number;
	}

	printf("%d\n", sum);

	return 0;
}