#include<stdio.h>

int main(void)
{
	int N, count[1024]={0};
	long long number, friend=0;

	scanf("%d", &N);

	for(int i=0;i<N;++i)
	{
		int digit=0;

		scanf("%lld", &number);

		while(number)
		{
			digit|=1<<number%10;
			number/=10;
		}

		++count[digit];
	}

	for(int i=0;i<1024;++i)
		if(count[i])
		{
			for(int j=0;j<i;++j)
			{
				int overlap=0;

				for(int k=0;k<10;++k)
					if((i&(1<<k))&&(j&(1<<k)))
					{
						overlap=1;
						break;
					}

				if(overlap)
					friend+=(long long)count[i]*count[j];
			}

			friend+=(long long)count[i]*(count[i]-1)>>1;
		}

	printf("%lld", friend);
	return 0;
}