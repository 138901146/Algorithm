#include<stdio.h>

int main(void)
{
	int N, bitter[10], sour[10], min=2000000000;

	scanf("%d", &N);

	for(int n=0;n<N;n++)
		scanf("%d%d", &sour[n], &bitter[n]);

	for(int bit=1;bit<(1<<N);bit++)
	{
		int sum=0, mul=1, diff;

		for(int n=0;n<N;n++)
			if(bit&(1<<n))
			{
				sum+=bitter[n];
				mul*=sour[n];
			}

		diff=sum<mul?mul-sum:sum-mul;
		min=diff<min?diff:min;
	}

	printf("%d\n", min);
	return 0;
}