#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, K, X, *a=NULL, max=0;

	scanf("%d%d%d", &N, &K, &X);

	a=(int *)malloc((N+1)*sizeof(int));

	a[0]=0;
	for(int i=1;i<=N;++i)
	{
		scanf("%d", &a[i]);
		a[i]+=a[i-1];
	}

	for(int i=1;i<=N;++i)
	{
		int left=i, right=N, mid, end=i-1, total=X*a[i-1];

		while(left<=right)
		{
			mid=left+right>>1;

			if(total+a[N]-a[mid]<K)
				right=mid-1;
			else
			{
				end=mid;
				left=mid+1;
			}
		}

		max=end-i+1<max?max:end-i+1;
	}

	printf("%d", max?max:-1);

	free(a);
	return 0;
}