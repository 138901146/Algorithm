#include<stdio.h>

int main(void)
{
	int N;

	scanf("%d", &N);

	if(N<3)
		printf("%d\n", N);
	else
	{
		int index=0;

		while((1<<++index)<N);
		N-=(1<<index-1);

		printf("%d\n", N<<1);
	}

	return 0;
}