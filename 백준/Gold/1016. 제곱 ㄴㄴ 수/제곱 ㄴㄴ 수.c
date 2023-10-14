#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	long long min, max, count=0;
	bool multiple[1000001]={false};

	scanf("%lld%lld", &min, &max);

	for(long long i=2;i*i<=max;++i)
	{
		long long square=i*i, X=min/square;

		if(min%square)
			++X;

		while(X*square<=max)
			multiple[X++*square-min]=true;
	}

	max-=min;
	for(int i=0;i<=max;++i)
		count+=!multiple[i];

	printf("%lld", count);
	return 0;
}