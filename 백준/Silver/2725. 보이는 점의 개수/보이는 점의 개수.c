#include<stdio.h>

int GCD(int x,int y)
{
	int temp;

	while(y>0)
	{
		temp=x%y;
		x=y;
		y=temp;
	}

	return x;
}

int main(void)
{
	int C, N, visible[1001]={0, 3, 0, };

	for(int n=2;n<1001;n++)
	{
		for(int i=1;i<=n;i++)
			visible[n]+=GCD(n,i)==1;
		visible[n]<<=1;
		visible[n]+=visible[n-1];
	}

	scanf("%d", &C);

	for(int c=0;c<C;c++)
	{
		scanf("%d", &N);
		printf("%d\n", visible[N]);
	}

	return 0;
}