#include<stdio.h>

int main(void)
{
	int N, X[3000], T[3000], elapsed=0, last;

	scanf("%d", &N);
	for(int i=0;i<N;++i)
		scanf("%d", &X[i]);
	for(int i=0;i<N;++i)
		scanf("%d", &T[i]);

	last=X[N-1];
	elapsed=last<T[N-1]?T[N-1]:last;

	X[N-1]=0;
	for(int i=N-2;0<=i;--i)
	{
		X[i]=last-X[i];
		elapsed=elapsed+X[i]-X[i+1]<T[i]?T[i]:elapsed+X[i]-X[i+1];
	}

	printf("%d", elapsed+last-X[0]);
	return 0;
}