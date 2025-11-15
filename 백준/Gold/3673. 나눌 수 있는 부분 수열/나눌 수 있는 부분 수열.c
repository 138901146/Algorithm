#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int C;

	scanf("%d", &C);

	while(C--)
	{
		int d, n;
		long long *arr=NULL, count=0, *remain=NULL;

		scanf("%d%d", &d, &n);
		arr=(long long *)calloc(n+1,sizeof(long long));
		remain=(long long *)calloc(d,sizeof(long long));
		remain[0]=1;

		for(int i=1;i<=n;++i)
		{
			scanf("%lld", &arr[i]);
			arr[i]+=arr[i-1];
			count+=remain[arr[i]%d];
			remain[arr[i]%d]++;
		}

		printf("%lld\n", count);
		free(arr);
		free(remain);
	}

	return 0;
}