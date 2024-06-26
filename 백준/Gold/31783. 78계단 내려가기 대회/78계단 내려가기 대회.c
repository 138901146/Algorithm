#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, *H=NULL, *A=NULL, B;
	long long *max=NULL;

	scanf("%d", &N);
	H=(int *)malloc(N*sizeof(int));
	A=(int *)malloc(N*sizeof(int));
	max=(long long *)calloc(N,sizeof(long long));

	for(int i=0;i<N;++i)
		scanf("%d", &H[i]);
	for(int i=1;i<N;++i)
		scanf("%d", &A[i]);

	for(int i=1;i<N;++i)
	{
		int left=0, right=i-1, mid, point=i-1;

		scanf("%d", &B);

		while(left<=right)
		{
			mid=left+right>>1;

			if(H[mid]<H[i]+B)
				right=mid-1;
			else
			{
				left=mid+1;
				point=mid;
			}
		}

		if(H[i]+B<=H[point])
			max[i]=max[point]+A[i];
		max[i]=max[i]<max[i-1]?max[i-1]:max[i];
	}

	printf("%lld", max[N-1]);
	free(H);
	free(A);
	free(max);
	return 0;
}