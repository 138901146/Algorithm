#include<stdio.h>

int main(void)
{
	int N, id, count=0;

	scanf("%d", &N);

	for(int i=1;i<=N;++i)
	{
		scanf("%d", &id);
		count+=i!=id;
	}

	printf("%d", count);
	return 0;
}