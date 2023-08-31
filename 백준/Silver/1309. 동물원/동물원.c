#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, *cage=NULL, *until=NULL;

	scanf("%d", &N);
	cage=(int *)malloc(N*sizeof(int));
	until=(int *)malloc(N*sizeof(int));

	cage[0]=1;
	until[0]=3;

	for(int n=1;n<N;n++)
	{
		cage[n]=cage[n-1]+(n>1?until[n-2]:1);
		until[n]=until[n-1]+(cage[n]<<1);

		cage[n]%=9901;
		until[n]%=9901;
	}

	printf("%d\n", until[N-1]);
	free(until);
	free(cage);
	return 0;
}