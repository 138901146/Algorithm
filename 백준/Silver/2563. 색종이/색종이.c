#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void)
{
	int N, area=0;
	bool **paper=NULL;

	paper=(bool **)malloc(100*sizeof(bool *));
	for(int i=0;i<100;i++)
		paper[i]=(bool *)calloc(100,sizeof(bool));

	scanf("%d", &N);

	for(int i=0;i<N;i++)
	{
		int X, Y;

		scanf("%d %d", &X, &Y);

		for(int x=X;x<X+10;x++)
			for(int y=Y;y<Y+10;y++)
				paper[x][y]=true;
	}

	for(int x=0;x<100;x++)
		for(int y=0;y<100;y++)
			area+=paper[x][y];

	printf("%d\n", area);

	for(int i=0;i<100;i++)
		free(paper[i]);
	free(paper);
	return 0;
}