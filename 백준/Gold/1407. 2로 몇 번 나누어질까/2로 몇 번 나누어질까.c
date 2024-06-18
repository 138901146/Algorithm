#include<stdio.h>

int main(void)
{
	long long A, B, count[51]={0}, answer=0;

	scanf("%lld%lld", &A, &B);

	count[0]=B-A+1;
	for(int i=1;(long long)1<<i<=B;++i)
	{
		long long left=(A-1)/((long long)1<<i), right=B/((long long)1<<i);

		count[i]=right-left;
		count[i-1]-=count[i];
	}

	for(int i=0;i<51;++i)
		answer+=count[i]*((long long)1<<i);

	printf("%lld", answer);
	return 0;
}