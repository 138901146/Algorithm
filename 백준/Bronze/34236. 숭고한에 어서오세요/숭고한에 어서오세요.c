#include<stdio.h>

int main(void)
{
	int N, A[2];

	scanf("%d", &N);

	for(int i=0;i<2;++i)
		scanf("%d", &A[i]);

	printf("%d", A[0]+N*(A[1]-A[0]));
	return 0;
}