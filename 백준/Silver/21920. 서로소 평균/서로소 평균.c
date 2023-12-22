#include<stdio.h>
#include<malloc.h>

int gcd(int x,int y)
{
	int temp;

	if(x<y)
	{
		temp=x;
		x=y;
		y=temp;
	}

	while(y)
	{
		temp=x%y;
		x=y;
		y=temp;
	}

	return x;
}

int main(void)
{
	int N, *A=NULL, X, count=0;
	double sum=0.0;

	scanf("%d", &N);
	A=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &A[i]);
	scanf("%d", &X);

	for(int i=0;i<N;++i)
		if(gcd(X,A[i])==1)
		{
			sum+=(double)A[i];
			++count;
		}

	printf("%lf", (double)sum/count);
	free(A);
	return 0;
}