#include<stdio.h>

int main(void)
{
	int N, price[50], deliver[50], max=0, profit=0, highest=0;

	scanf("%d", &N);

	for(int i=0;i<N;++i)
	{
		scanf("%d%d", &price[i], &deliver[i]);
		highest=price[i]<highest?highest:price[i];
	}

	for(int i=1;i<=highest;++i)
	{
		int current=0;

		for(int j=0;j<N;++j)
			if(i<=price[j]&&deliver[j]<i)
				current+=i-deliver[j];

		if(profit<current)
		{
			max=i;
			profit=current;
		}
	}

	printf("%d", max);
	return 0;
}