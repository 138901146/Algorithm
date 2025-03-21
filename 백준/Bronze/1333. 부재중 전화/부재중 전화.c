#include<stdio.h>

int main(void)
{
	int N, L, D, count=0;

	scanf("%d%d%d", &N, &L, &D);

	for(int n=0;n<N;++n)
	{
		count+=L;

		for(int i=0;i<5;++i)
			if(!((count+i)%D))
			{
				printf("%d", count+i);
				return 0;
			}

		count+=5;
	}

	while(count%D)
		++count;

	printf("%d", count);
	return 0;
}