#include<stdio.h>

int main(void)
{
	int N, count=0;
	long long descending=0;

	scanf("%d", &N);

	if(N>1022)
	{
		printf("-1\n");
		return 0;
	}

	while(count<N)
	{
		long long temp=descending;
		int digit=0;

		while(temp%10+1==(temp/10)%10)
		{
			temp/=10;
			digit++;
		}

		if(temp==9)
		{
			descending=0;
			for(int i=digit+1;i>0;i--)
			{
				descending+=i;
				descending*=10;
			}
		}
		else
		{
			temp=1;
			for(int i=0;i<digit;i++)
				temp*=10;
			descending+=temp;
			descending-=descending%temp;
			temp=0;
			for(int i=digit-1;i>=0;i--)
			{
				temp*=10;
				temp+=i;
			}
			descending+=temp;
		}

		count++;
	}

	printf("%lld\n", descending);
	return 0;
}