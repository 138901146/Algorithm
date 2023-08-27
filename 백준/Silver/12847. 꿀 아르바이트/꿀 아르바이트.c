#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int n, m;
	long long *T=NULL, max=0;

	scanf("%d%d", &n, &m);
	T=(long long *)calloc(n+1,sizeof(long long));

	for(int i=1;i<=n;i++)
	{
		scanf("%lld", &T[i]);
		T[i]+=T[i-1];

		if(m<=i)
			max=T[i]-T[i-m]>max?T[i]-T[i-m]:max;
	}

	printf("%lld\n", max);
	free(T);
	return 0;
}