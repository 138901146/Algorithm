#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

int main(void)
{
	int N, *S=NULL, total=0;
	bool *partial_sum=NULL;

	scanf("%d", &N);
	S=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;n++)
	{
		scanf("%d", &S[n]);
		total+=S[n];
	}
	partial_sum=(bool *)calloc(total+2,sizeof(bool));

	for(int bit=1;bit<(1<<N);bit++)
	{
		int sum=0;

		for(int n=0;n<N;n++)
			if(bit&(1<<n))
				sum+=S[n];

		partial_sum[sum]=true;
	}

	for(int i=1;i<total+2;i++)
		if(!partial_sum[i])
		{
			printf("%d\n", i);
			break;
		}
	free(S);
	free(partial_sum);
	return 0;
}