#include<stdio.h>

int main(void)
{
	int N, A[1000], B, total=0, myview=0;

	scanf("%d", &N);

	for(int i=0;i<N;++i)
	{
		scanf("%d", &A[i]);
		total+=A[i];
	}

	for(int i=0;i<N;++i)
	{
		scanf("%d", &B);
		myview+=B?0:A[i];
	}

	printf("%d\n%d", total, myview);
	return 0;
}