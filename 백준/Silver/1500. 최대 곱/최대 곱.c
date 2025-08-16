#include<stdio.h>

int main(void)
{
	unsigned long long S, K, mod, ans=1;

	scanf("%lld%lld", &S, &K);

	mod=S%K;
	for(int i=0;i<K;++i)
		ans*=S/K+(i<mod);

	printf("%llu", ans);
	return 0;
}