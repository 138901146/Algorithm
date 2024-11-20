#include<stdio.h>

int main(void)
{
	long long N, last=-1;

	scanf("%lld", &N);

	if(!N)
	{
		printf("NO");
		return 0;
	}

	while(0<N)
	{
		long long current=1;

		while(current<=N)
			current*=3;
		current/=3;

		if(current==last)
		{
			printf("NO");
			return 0;
		}

		N-=current;
		last=current;
	}

	printf("YES");
	return 0;
}