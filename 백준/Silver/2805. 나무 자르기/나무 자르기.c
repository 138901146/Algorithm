#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, *height=0;
	long long M, left=0, right=2100000000, H=0;

	scanf("%d%lld", &N, &M);
	height=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &height[i]);

	while(left<=right)
	{
		long long length=0, mid=left+right>>1;

		for(int i=0;i<N;++i)
			length+=height[i]<mid?0:height[i]-mid;

		if(length<M)
			right=mid-1;
		else
		{
			left=mid+1;
			H=mid;
		}
	}

	printf("%lld", H);
	free(height);
	return 0;
}