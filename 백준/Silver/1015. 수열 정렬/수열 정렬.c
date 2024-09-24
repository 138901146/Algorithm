#include<stdio.h>

int main(void)
{
	int N, A[50], B[50], count=0;

	scanf("%d", &N);

	for(int i=0;i<N;++i)
		scanf("%d", &A[i]);

	for(int i=1;i<1001;++i)
		for(int n=0;n<N;++n)
			if(A[n]==i)
				B[n]=count++;

	for(int i=0;i<N;++i)
		printf("%d ", B[i]);
	return 0;
}