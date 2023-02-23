#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, dice[6], **order=NULL, max=0;

	scanf("%d", &N);
	order=(int **)malloc(N*sizeof(int *));
	for(int n=0;n<N;n++)
		order[n]=(int *)calloc(6,sizeof(int));

	for(int n=0;n<N;n++)
	{
		for(int i=0;i<6;i++)
			scanf("%d", &dice[i]);

		order[n][dice[0]-1]=dice[5]-1;
		order[n][dice[1]-1]=dice[3]-1;
		order[n][dice[2]-1]=dice[4]-1;
		order[n][dice[3]-1]=dice[1]-1;
		order[n][dice[4]-1]=dice[2]-1;
		order[n][dice[5]-1]=dice[0]-1;
	}

	for(int state=0;state<6;state++)
	{
		int sum=0, current=state;

		for(int n=0;n<N;n++)
		{
			if(order[n][current]==5)
				sum+=current==4?4:5;
			else if(order[n][current]==4)
				sum+=current==5?4:6;
			else
				sum+=current==5?5:6;

			current=order[n][current];
		}

		max=sum>max?sum:max;
	}

	printf("%d\n", max);
	for(int n=0;n<N;n++)
		free(order[n]);
	free(order);
	return 0;
}