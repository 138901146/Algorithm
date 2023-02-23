#include<stdio.h>

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

int lcm(int x,int y)
{
	return x*y/gcd(x,y);
}

int main(void)
{
	int A[2], B[2], C;

	for(int i=0;i<2;i++)
		scanf("%d %d", &A[i], &B[i]);

	for(int i=0;i<2;i++)
		A[i]*=lcm(B[0],B[1])/B[i];
	B[0]=B[1]=lcm(B[0],B[1]);

	A[0]+=A[1];

	C=gcd(A[0],B[0]);
	A[0]/=C;
	B[0]/=C;

	printf("%d %d\n", A[0], B[0]);

	return 0;
}