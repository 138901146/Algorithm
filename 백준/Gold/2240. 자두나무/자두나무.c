#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int T, W, ***max=NULL, plum;

	scanf("%d%d", &T, &W);
	max=(int ***)malloc((T+1)*sizeof(int **));
	for(int t=0;t<=T;t++)
	{
		max[t]=(int **)malloc((W+1)*sizeof(int *));
		for(int w=0;w<=W;w++)
			max[t][w]=(int *)calloc(2,sizeof(int));
	}

	scanf("%d", &plum);
	if(plum==1)
		max[1][0][0]=1;
	else
		max[1][1][1]=1;
	for(int t=2;t<=T;t++)
	{
		scanf("%d", &plum);
		plum--;

		max[t][0][plum]=max[t-1][0][plum]+1;
		max[t][0][(plum+1)&1]=max[t-1][0][(plum+1)&1];
		for(int w=1;w<=W;w++)
		{
			max[t][w][plum]=max[t-1][w][plum]+1>max[t-1][w-1][(plum+1)&1]+1?max[t-1][w][plum]+1:max[t-1][w-1][(plum+1)&1]+1;
			max[t][w][(plum+1)&1]=max[t-1][w][(plum+1)&1];
		}
	}

	plum=0;
	for(int w=0;w<=W;w++)
		for(int i=0;i<2;i++)
			plum=max[T][w][i]>plum?max[T][w][i]:plum;

	printf("%d\n", plum);
	for(int t=0;t<=T;t++)
	{
		for(int w=0;w<=W;w++)
			free(max[t][w]);
		free(max[t]);
	}
	free(max);
	return 0;
}