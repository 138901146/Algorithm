#include<stdio.h>

int main(void)
{
	unsigned long long int sum=0, N;

	scanf("%llu", &N);

	for(unsigned long long int i=1;i<N;i++)
		if(((N+1)*i)%N==((N+1)*i)/N)
			sum+=(N+1)*i;

	printf("%llu\n", sum);
	return 0;
}