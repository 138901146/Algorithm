#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, *D=NULL, *V=NULL, left, right=0, ans;

	scanf("%d", &N);
	D=(int *)malloc(N*sizeof(int));
	V=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;++n)
	{
		scanf("%d%d", &D[n], &V[n]);
		right+=V[n];
	}

	ans=left=V[0];

	while(left<=right)
	{
		int mid=left+right>>1, available=1, sum=0;

		mid=left+right>>1;

		for(int n=0;n<N;++n)
		{
			sum+=V[n];
			if(mid<sum)
			{
				available=0;
				break;
			}
			mid+=D[n];
		}

		mid=left+right>>1;

		if(available)
		{
			ans=mid;
			right=mid-1;
		}
		else
			left=mid+1;
	}

	printf("%d", ans);
	free(D);
	free(V);
	return 0;
}