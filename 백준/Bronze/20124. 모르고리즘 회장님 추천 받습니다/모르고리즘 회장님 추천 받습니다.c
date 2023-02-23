#include<stdio.h>
#include<string.h>

int main(void)
{
	int N, maxB=0, B;
	char maxA[11], A[11];

	scanf("%d", &N);

	for(int n=0;n<N;n++)
	{
		scanf("%s %d", A, &B);

		if(B>maxB || B==maxB && strcmp(A,maxA)<0)
		{
			maxB=B;
			strcpy(maxA,A);
		}
	}

	printf("%s\n", maxA);
	return 0;
}