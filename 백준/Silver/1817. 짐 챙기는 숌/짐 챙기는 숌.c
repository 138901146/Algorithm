#include<stdio.h>

int main(void)
{
	int N, M, book, count=0, weight=0;

	scanf("%d%d", &N, &M);

	if(!N)
	{
		printf("0");
		return 0;
	}

	for(int n=0;n<N;++n)
	{
		scanf("%d", &book);

		if(weight+book<=M)
			weight+=book;
		else
		{
			++count;
			weight=book;
		}
	}

	printf("%d", count+(0<weight));
	return 0;
}