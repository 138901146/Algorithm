#include<stdio.h>
#include<stdlib.h>

int min3(int X,int Y,int Z)
{
	return X<=Y&&X<=Z?X:Y<=X&&Y<=Z?Y:Z;
}

int min2(int X,int Y)
{
	return X<Y?X:Y;
}

int main(void)
{
	int *X=NULL, N;

	scanf("%d", &N);
	X=(int *)calloc(N+1,sizeof(int));

	for(int i=2;i<=N;i++)
		if(i%6==0)
			X[i]=min3(X[i-1],X[i/2],X[i/3])+1;
		else if(i%2==0)
			X[i]=min2(X[i-1],X[i/2])+1;
		else if(i%3==0)
			X[i]=min2(X[i-1],X[i/3])+1;
		else
			X[i]=X[i-1]+1;

	printf("%d\n", X[N]);
	free(X);
	return 0;
}