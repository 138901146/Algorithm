#include<stdio.h>
#include<malloc.h>

int main(void)
{
	long long n, *cross=NULL, *left=NULL, *right=NULL, min_cross, min_distance=100000000000000;

	scanf("%lld", &n);
	cross=(long long *)calloc(n+1,sizeof(long long));
	left=(long long *)calloc(n+1,sizeof(long long));
	right=(long long *)calloc(n+1,sizeof(long long));

	for(int i=1;i<=n;++i)
		scanf("%lld", &cross[i]);

	for(int i=1;i<=n-1;++i)
	{
		scanf("%lld", &left[i]);
		left[i]+=left[i-1];
	}

	for(int i=1;i<=n-1;++i)
		scanf("%lld", &right[i]);

	for(int i=n-1;0<=i;--i)
		right[i]+=right[i+1];

	for(int i=1;i<=n;++i)
		if(left[i-1]+right[i]+cross[i]<min_distance)
		{
			min_distance=left[i-1]+right[i]+cross[i];
			min_cross=i;
		}

	printf("%lld %lld", min_cross, min_distance);
	free(cross);
	free(left);
	free(right);
	return 0;
}