#include<stdio.h>

long long N, max=0;
int K[3], count;

void calculate_max(long long current)
{
	if(N<current)
		return;

	max=current<max?max:current;

	for(int i=0;i<count;++i)
		calculate_max((long long)10*current+K[i]);
}

int main(void)
{
	scanf("%lld%d", &N, &count);
	for(int i=0;i<count;++i)
		scanf("%d", &K[i]);

	calculate_max(0);

	printf("%lld", max);
	return 0;
}