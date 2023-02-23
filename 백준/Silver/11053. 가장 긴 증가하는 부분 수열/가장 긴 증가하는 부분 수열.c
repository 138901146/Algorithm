#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, *A=NULL, num, max=1;

	scanf("%d", &N);
	A=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;n++)
	{
		scanf("%d", &num);
		A[n]=10000+num;

		for(int i=0;i<n;i++)
			A[n]=A[i]%10000<num&&A[i]/10000>=A[n]/10000?10000*((A[i]/10000)+1)+num:A[n];

		max=A[n]/10000>max?A[n]/10000:max;
	}

	printf("%d\n", max);
	free(A);
	return 0;
}