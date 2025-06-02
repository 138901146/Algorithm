#include<stdio.h>

int main(void)
{
	int n, a[1000];
	long long total[1000]={0}, max=0;

	scanf("%d", &n);

	for(int i=0;i<n;++i)
	{
		scanf("%d", &a[i]);

		for(int j=0;j<i;++j)
			total[i]=a[j]<a[i]&&total[i]<total[j]?total[j]:total[i];
		total[i]+=a[i];

		max=total[i]<max?max:total[i];
	}

	printf("%lld", max);
	return 0;
}