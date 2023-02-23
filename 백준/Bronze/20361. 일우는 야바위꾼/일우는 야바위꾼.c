#include<stdio.h>

int main(void)
{
	int N, X, K, A, B;

	scanf("%d %d %d", &N, &X, &K);

	for(int i=0;i<K;i++)
	{
		scanf("%d %d", &A, &B);

		if(A==X)
			X=B;
		else if(B==X)
			X=A;
	}

	printf("%d\n", X);
	return 0;
}