#include<stdio.h>

int main(void)
{
	int N, sum;
	long long id;

	scanf("%d", &N);

	while(N--)
	{
		scanf("%lld", &id);

		sum=(id%1000)*10;
		while(id)
		{
			sum+=id%10;
			id/=10;
		}

		if(9999<sum)
			sum%=10000;
		else if(sum<1000)
			sum+=1000;

		printf("%04d\n", sum);
	}

	return 0;
}