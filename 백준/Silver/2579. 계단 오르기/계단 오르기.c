#include<stdio.h>
#include<stdlib.h>

int max(int x,int y)
{
	return x>y?x:y;
}

int main(void)
{
	int *stairs=NULL, num, **score=NULL;

	scanf("%d", &num);
	stairs=(int *)calloc(num+1,sizeof(int));
	score=(int **)malloc((num+1)*sizeof(int *));
	for(int i=0;i<=num;i++)
		score[i]=(int *)calloc(2,sizeof(int));

	for(int i=1;i<=num;i++)
		scanf("%d", &stairs[i]);

	score[1][0]=stairs[1];
	for(int i=2;i<=num;i++)
	{
		score[i][0]=stairs[i]+max(score[i-2][0],score[i-2][1]);
		score[i][1]=stairs[i]+score[i-1][0];
	}

	printf("%d\n", max(score[num][0],score[num][1]));
	for(int i=0;i<=num;i++)
		free(score[i]);
	free(score);
	free(stairs);
	return 0;
}