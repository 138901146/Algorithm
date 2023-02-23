#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, C, *period=NULL, exploded=0;

	scanf("%d %d", &N, &C);
	period=(int *)malloc(N*sizeof(int));
	for(int i=0;i<N;i++)
		scanf("%d", &period[i]);

	for(int c=1;c<=C;c++)
		for(int i=0;i<N;i++)
			if(c%period[i]==0)
			{
				exploded++;
				break;
			}

	printf("%d\n", exploded);
	free(period);
	return 0;
}