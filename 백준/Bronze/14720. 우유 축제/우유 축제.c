#include<stdio.h>

int main(void)
{
	int N, milk, count=0;

	scanf("%d", &N);

	for(int i=0;i<N;i++)
	{
		scanf("%d", &milk);
		count+=count%3==milk;
	}

	printf("%d", count);
	return 0;
}