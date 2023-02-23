#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void)
{
	int N, M, *K=NULL, sum=0;

	scanf("%d %d", &N, &M);
	K=(int *)malloc(M*sizeof(int));

	for(int i=0;i<M;i++)
		scanf("%d", &K[i]);

	for(int i=K[0];i<=N;i++)
	{
		bool multiple=false;

		for(int j=0;j<M;j++)
			if(i>=K[j] && i%K[j]==0)
			{
				multiple=true;
				break;
			}

		if(multiple)
			sum+=i;
	}

	printf("%d\n", sum);
	free(K);
	return 0;
}