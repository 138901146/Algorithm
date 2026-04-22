#include<stdio.h>

int main(void)
{
	int N, count[96000]={0}, start_year, start_month, end_year, end_month, max=0;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%4d-%2d %4d-%2d", &start_year, &start_month, &end_year, &end_month);
		++count[(start_year-2000)*12+start_month-1];
		--count[(end_year-2000)*12+end_month];
	}

	for(int i=1;i<96000;++i)
	{
		count[i]+=count[i-1];
		max=count[max]<count[i]?i:max;
	}

	printf("%4d-%02d", max/12+2000, max%12+1);
	return 0;
}