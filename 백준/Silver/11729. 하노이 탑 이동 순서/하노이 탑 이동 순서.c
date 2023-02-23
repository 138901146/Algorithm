#include<stdio.h>

int N=1;

void moveHanoiquietly(int from,int temp,int to,int n)
{
	if(n==1)
		N++;
	else
	{
		moveHanoiquietly(from,to,temp,n-1);
		N++;
		moveHanoiquietly(temp,from,to,n-1);
	}
}

void moveHanoi(int from,int temp,int to,int n)
{
	if(n==1)
	{
		N++;
		printf("%d %d\n",from, to);
	}
	else
	{
		moveHanoi(from,to,temp,n-1);
		N++;
		printf("%d %d\n", from, to);
		moveHanoi(temp,from,to,n-1);
	}
}

int main(void)
{
	int n;

	scanf("%d", &n);

	moveHanoiquietly(1,2,3,n);
	printf("%d\n", --N);
	N=1;
	moveHanoi(1,2,3,n);

	return 0;
}