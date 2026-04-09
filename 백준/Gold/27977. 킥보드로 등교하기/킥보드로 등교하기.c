#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int L, N, K, *A=NULL, left=0, right, battery;

	scanf("%d%d%d", &L, &N, &K);

	A=(int *)calloc(N+2,sizeof(int));

	for(int i=1;i<=N;++i)
		scanf("%d", &A[i]);

	A[N+1]=battery=right=L;
	while(left<=right)
	{
		int mid=left+right>>1, current=mid, count=0;

		for(int i=1;i<N+2;++i)
			if(mid<A[i]-A[i-1])
			{
				count=123456789;
				break;
			}
			else if(current<A[i]-A[i-1])
			{
				++count;
				current=mid+A[i-1]-A[i];
			}
			else
				current-=A[i]-A[i-1];

		if(count<=K)
		{
			battery=mid;
			right=mid-1;
		}
		else
			left=mid+1;
	}

	printf("%d", battery);

	free(A);
	return 0;
}