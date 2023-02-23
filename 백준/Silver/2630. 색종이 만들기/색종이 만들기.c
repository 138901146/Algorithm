#include<stdio.h>
#include<stdlib.h>

int **paper=NULL, white=0, blue=0;

void count_color(int locate,int N)
{
	int x=locate/1000, y=locate%1000, count=0;

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			count+=paper[x+i][y+j];

	if(count==0)
		white++;
	else if(count==N*N)
		blue++;
	else
	{
		count_color(1000*x+y,N/2);
		count_color(1000*(x+N/2)+y,N/2);
		count_color(1000*x+y+N/2,N/2);
		count_color(1000*(x+N/2)+y+N/2,N/2);
	}
}

int main(void)
{
	int N;

	scanf("%d", &N);
	paper=(int **)malloc(N*sizeof(int *));
	for(int i=0;i<N;i++)
	{
		paper[i]=(int *)malloc(N*sizeof(int));

		for(int j=0;j<N;j++)
			scanf("%d", &paper[i][j]);
	}

	count_color(0,N);

	printf("%d\n%d\n", white, blue);
	for(int i=0;i<N;i++)
		free(paper[i]);
	free(paper);
	return 0;
}