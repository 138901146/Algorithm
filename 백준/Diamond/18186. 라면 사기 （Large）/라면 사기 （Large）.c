#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, *A=NULL;
	long long B, C, cost=0, ramen;

	scanf("%d%lld%lld", &N, &B, &C);

	A=(int *)calloc(N+2,sizeof(int));
	for(int i=0;i<N;i++)
		scanf("%d", &A[i]);

	if(B<=C)
	{
		for(int i=0;i<N;i++)
			cost+=A[i];

		printf("%lld\n", cost*B);
		free(A);
		return 0;
	}

	for(int i=0;i<N;i++)
	{
		if(A[i+1]>A[i+2])
		{
			ramen=A[i]<A[i+1]-A[i+2]?A[i]:A[i+1]-A[i+2];
			cost+=(B+C)*ramen;

			A[i]-=ramen;
			A[i+1]-=ramen;

			ramen=A[i]<=A[i+1]&&A[i]<=A[i+2]?A[i]:A[i+1]<=A[i]&&A[i+1]<=A[i+2]?A[i+1]:A[i+2];
			cost+=(B+2*C)*ramen;

			A[i]-=ramen;
			A[i+1]-=ramen;
			A[i+2]-=ramen;
		}
		else
		{
			ramen=A[i]<=A[i+1]&&A[i]<=A[i+2]?A[i]:A[i+1]<=A[i]&&A[i+1]<=A[i+2]?A[i+1]:A[i+2];
			cost+=(B+2*C)*ramen;

			A[i]-=ramen;
			A[i+1]-=ramen;
			A[i+2]-=ramen;

			ramen=A[i]<A[i+1]?A[i]:A[i+1];
			cost+=(B+C)*ramen;

			A[i]-=ramen;
			A[i+1]-=ramen;
		}

		cost+=B*A[i];
	}

	printf("%lld\n", cost);
	free(A);
	return 0;
}