#include<stdio.h>

int N, K, A[5], R[4][5], M[4][5], max=0;

void can(int current,int satisfy)
{
	if(current==(K<<1))
		max=satisfy<max?max:satisfy;
	else if(current&1)
	{
		for(int i=0;i<N;++i)
			if(A[i])
			{
				--A[i];
				can(current+1,satisfy+R[current>>1][i]);
				++A[i];
			}
	}
	else
		for(int i=0;i<N;++i)
			if(A[i])
			{
				--A[i];
				can(current+1,satisfy+M[current>>1][i]);
				++A[i];
			}
}

int main(void)
{
	scanf("%d%d", &N, &K);
	for(int i=0;i<N;++i)
		scanf("%d", &A[i]);
	for(int i=0;i<K;++i)
		for(int j=0;j<N;++j)
			scanf("%d", &R[i][j]);
	for(int i=0;i<K;++i)
		for(int j=0;j<N;++j)
			scanf("%d", &M[i][j]);

	can(0,0);

	printf("%d", max);
	return 0;
}