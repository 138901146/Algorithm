#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(unsigned long long int *)x>*(unsigned long long int *)y?1:*(unsigned long long int *)x==*(unsigned long long int *)y?0:-1;
}

int main(void)
{
	int N;
	unsigned long long int *t=NULL, M=0;

	scanf("%d", &N);
	t=(unsigned long long int *)malloc(N*sizeof(unsigned long long int));
	for(int i=0;i<N;i++)
		scanf("%llu", &t[i]);

	qsort((void *)t,(size_t)N,sizeof(unsigned long long int),compare);

	if(N%2==1)
	{
		M=t[N-1];

		for(int i=0;i<N/2;i++)
			M=t[i]+t[N-i-2]>M?t[i]+t[N-i-2]:M;
	}
	else
		for(int i=0;i<N/2;i++)
			M=t[i]+t[N-i-1]>M?t[i]+t[N-i-1]:M;

	printf("%llu\n", M);
	free(t);
	return 0;
}