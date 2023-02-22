#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N;
	long int *count=NULL;

	scanf("%d", &N);
	count=(long int *)malloc((N+1)*sizeof(long int));

	count[0]=1;
	count[1]=0;
	for(int i=2;i<=N;i++)
		count[i]=((i-1)*(count[i-1]+count[i-2]))%1000000000;

	printf("%ld\n", count[N]);
	free(count);
	return 0;
}