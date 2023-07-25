#include<stdio.h>

int main(void)
{
	int T, n;
	long long count[100001];

	count[0]=count[1]=1;
	count[2]=count[3]=2;
	count[4]=count[5]=3;
	for(int i=6;i<100001;i++)
		count[i]=(count[i-2]+count[i-4]+count[i-6])%1000000009;

	scanf("%d", &T);
	for(int t=0;t<T;t++)
	{
		scanf("%d", &n);
		printf("%lld\n", count[n]);
	}

	return 0;
}