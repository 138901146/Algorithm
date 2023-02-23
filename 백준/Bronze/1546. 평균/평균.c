#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int M=0, N, *score=NULL;
	float avr=0.0;

	scanf("%d", &N);
	score=(int *)malloc(N*sizeof(int));
	for(int i=0;i<N;i++)
	{
		scanf("%d", &score[i]);
		M=score[i]>M?score[i]:M;
	}

	for(int i=0;i<N;i++)
		avr+=(float)score[i]/M*100;
	avr/=(float)N;

	printf("%f\n", avr);

	free(score);
	return 0;
}