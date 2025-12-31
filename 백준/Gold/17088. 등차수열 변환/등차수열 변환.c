#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

#define INF 123456

int abs(int x)
{
	return x<0?-x:x;
}

int main(void)
{
	int N, *A=NULL, *B=NULL, min=INF;

	scanf("%d", &N);

	if(N==1)
	{
		printf("0");
		return 0;
	}

	A=(int *)malloc(N*sizeof(int));
	B=(int *)malloc(N*sizeof(int));
	for(int i=0;i<N;++i)
		scanf("%d", &A[i]);

	for(int primary_diff=-1;primary_diff<2;++primary_diff)
	{
		int count, diff;

		B[0]=A[0]+primary_diff;

		for(int secondary_diff=-1;secondary_diff<2;++secondary_diff)
		{
			bool available=true;

			B[1]=A[1]+secondary_diff;
			diff=B[1]-B[0];
			count=abs(primary_diff)+abs(secondary_diff);

			for(int i=2;i<N&&available;++i)
			{
				available=false;

				for(int x=-1;x<2;++x)
					if(B[i-1]+x+diff==A[i])
					{
						available=true;
						count+=abs(x);
						B[i]=B[i-1]+diff;
						break;
					}
			}

			if(available)
				min=count<min?count:min;
		}
	}

	printf("%d", min==INF?-1:min);
	free(A);
	free(B);
	return 0;
}