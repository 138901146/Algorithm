#include<stdio.h>

int main(void)
{
	int N, Y=0, M=0, time;

	scanf("%d", &N);

	for(int n=0;n<N;n++)
	{
		scanf("%d", &time);

		Y+=10*((time/30)+1);
		M+=15*((time/60)+1);
	}

	if(Y>M)
		printf("M %d\n", M);
	else if(Y<M)
		printf("Y %d\n", Y);
	else
		printf("Y M %d\n", Y);
	return 0;
}