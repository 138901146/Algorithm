#include<stdio.h>

int main(void)
{
	unsigned long long S, K, mod, ans=1;

	scanf("%lld%lld", &S, &K);

	mod=S%K;
	for(int i=0;i<mod;++i)
		ans*=S/K+1;
	for(int i=mod;i<K;++i)
		ans*=S/K;

	printf("%llu", ans);
	return 0;
}