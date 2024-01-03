#include<stdio.h>

int main(void)
{
	int N, s, continuous=0, max=0;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%d", &s);

		continuous=s?continuous+1:0;
		max=continuous>max?continuous:max;
	}

	printf("%d", max);
	return 0;
}