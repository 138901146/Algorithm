#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int C;

	scanf("%d", &C);

	for(int i=0;i<C;i++)
	{
		int N, *score=NULL, count=0;
		float avr=0.0;

		scanf("%d", &N);
		score=(int *)malloc(N*sizeof(int));

		for(int j=0;j<N;j++)
		{
			scanf("%d", &score[j]);
			avr+=(float)score[j];
		}
		avr/=N;

		for(int j=0;j<N;j++)
			count+=score[j]>avr;

		printf("%.3f%%\n", (100.0*count)/N);
		free(score);
	}

	return 0;
}