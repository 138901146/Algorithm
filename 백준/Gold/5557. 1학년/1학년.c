#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, *number=NULL;
	unsigned long long int **count=NULL;

	scanf("%d", &N);
	number=(int *)malloc(N*sizeof(int));
	count=(unsigned long long int **)malloc(N*sizeof(unsigned long long int *));
	for(int n=0;n<N;n++)
		count[n]=(unsigned long long int *)calloc(21,sizeof(unsigned long long int));

	for(int n=0;n<N;n++)
		scanf("%d", &number[n]);

	count[0][number[0]]=1;
	for(int i=1;i<N-1;i++)
		for(int j=0;j<21;j++)
		{
			if(j+number[i]<21)
				count[i][j+number[i]]+=count[i-1][j];
			if(j-number[i]>=0)
				count[i][j-number[i]]+=count[i-1][j];
		}

	printf("%llu\n", count[N-2][number[N-1]]);
	for(int n=0;n<N;n++)
		free(count[n]);
	free(count);
	free(number);
	return 0;
}