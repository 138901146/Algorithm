#include<stdio.h>
#include<stdlib.h>

int gcd(int x,int y)
{
	if(x<y)
	{
		int temp=x;
		x=y;
		y=temp;
	}

	while(y!=0)
	{
		int temp=x%y;
		x=y;
		y=temp;
	}

	return x;
}

int abs(int x)
{
	return x>0?x:-x;
}

int main(void)
{
	int N, *A=NULL, S, D=1000000000;

	scanf("%d %d", &N, &S);
	A=(int *)malloc(N*sizeof(int));
	for(int n=0;n<N;n++)
	{
		scanf("%d", &A[n]);
		D=n==0?abs(S-A[0]):gcd(D, abs(S-A[n]));
		if(D==1)
			break;
	}

	printf("%d\n", D);
	free(A);
	return 0;
}