#include<stdio.h>

int main(void)
{
	int N, A[10002]={0}, cost=0, ramen;

	scanf("%d", &N);

	for(int i=0;i<N;i++)
		scanf("%d", &A[i]);

	for(int i=0;i<N;i++)
	{
		if(A[i+1]>A[i+2])
		{
			ramen=A[i]<A[i+1]-A[i+2]?A[i]:A[i+1]-A[i+2];
			cost+=5*ramen;

			A[i]-=ramen;
			A[i+1]-=ramen;

			ramen=A[i]<=A[i+1]&&A[i]<=A[i+2]?A[i]:A[i+1]<=A[i]&&A[i+1]<=A[i+2]?A[i+1]:A[i+2];
			cost+=7*ramen;

			A[i]-=ramen;
			A[i+1]-=ramen;
			A[i+2]-=ramen;
		}
		else
		{
			ramen=A[i]<=A[i+1]&&A[i]<=A[i+2]?A[i]:A[i+1]<=A[i]&&A[i+1]<=A[i+2]?A[i+1]:A[i+2];
			cost+=7*ramen;

			A[i]-=ramen;
			A[i+1]-=ramen;
			A[i+2]-=ramen;

			ramen=A[i]<A[i+1]?A[i]:A[i+1];
			cost+=5*ramen;

			A[i]-=ramen;
			A[i+1]-=ramen;
		}

		cost+=3*A[i];
	}

	printf("%d\n", cost);
	return 0;
}