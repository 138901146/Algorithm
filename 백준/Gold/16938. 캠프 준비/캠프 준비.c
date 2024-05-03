#include<stdio.h>

int N, L, R, X, A[15], count=0;

void camp(int current,int min,int max,int sum)
{
	if(R<sum)
		return;

	count+=L<=sum && X<=max-min;

	if(current==N)
		return;

	for(int i=current;i<N;++i)
		camp(i+1,min<A[i]?min:A[i],max<A[i]?A[i]:max,sum+A[i]);
}

int main(void)
{
	scanf("%d%d%d%d", &N, &L, &R, &X);
	for(int i=0;i<N;++i)
		scanf("%d", &A[i]);

	camp(0,9999999,0,0);

	printf("%d", count);
	return 0;
}