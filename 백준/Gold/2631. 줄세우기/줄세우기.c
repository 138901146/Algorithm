#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, *children=NULL, *LIS=NULL, max=1;

	scanf("%d", &N);
	children=(int *)malloc(N*sizeof(int));
	LIS=(int *)malloc(N*sizeof(int ));
	for(int n=0;n<N;n++)
		scanf("%d", &children[n]);

	for(int i=N-1;i>=0;i--)
	{
		LIS[i]=1;
		for(int j=i+1;j<N;j++)
			if(children[i]<children[j] && LIS[i]<=LIS[j]+1)
				LIS[i]=LIS[j]+1;
		if(max<LIS[i])
			max=LIS[i];
	}

	printf("%d\n", N-max);
	free(children);
	free(LIS);
	return 0;
}