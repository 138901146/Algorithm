#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, *score=NULL, sum=0;

	scanf("%d", &N);
	score=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;i++)
		scanf("%d", &score[i]);

	for(int i=1;i<N;i++)
		if(score[i-1]*score[i]!=0)
			score[i]=score[i-1]+1;

	for(int i=0;i<N;i++)
		sum+=score[i];
	printf("%d\n", sum);

	free(score);
	return 0;
}