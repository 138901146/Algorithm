#include<stdio.h>
#include<stdlib.h>

int abs(int x)
{
	return x>0?x:-x;
}

int chicken_distance(int **chicken,int **house,int chicken_count,int house_count,int M,int current,int left)
{
	if(left==0 || chicken_count==M)
	{
		int sum=0;

		for(int i=0;i<house_count;i++)
		{
			int distance=99999999;

			for(int j=0;j<chicken_count;j++)
				if(chicken[j][0]!=-1 && chicken[j][1]!=-1)
					distance=abs(house[i][0]-chicken[j][0])+abs(house[i][1]-chicken[j][1])<distance?abs(house[i][0]-chicken[j][0])+abs(house[i][1]-chicken[j][1]):distance;

			sum+=distance;
		}

		return sum;
	}

	if(current+left<chicken_count)
	{
		int best=999999999;
		for(int i=current+1;i<chicken_count;i++)
		{
			int x=chicken[i][0], y=chicken[i][1];
			chicken[i][0]=chicken[i][1]=-1;

			int next=chicken_distance(chicken,house,chicken_count,house_count,M,i,left-1);
			best=next<best?next:best;
			chicken[i][0]=x;
			chicken[i][1]=y;
		}

		return best;
	}

	return 999999999;
}

int main(void)
{
	int N, M, **chicken=NULL, **map=NULL, **house=NULL, chicken_count=0, house_count=0;

	scanf("%d%d", &N, &M);
	map=(int **)malloc(N*sizeof(int *));
	for(int n=0;n<N;n++)
		map[n]=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			scanf("%d", &map[i][j]);
			chicken_count+=map[i][j]==2;
			house_count+=map[i][j]==1;
		}

	chicken=(int **)malloc(chicken_count*sizeof(int *));
	for(int i=0;i<chicken_count;i++)
		chicken[i]=(int *)malloc(2*sizeof(int));

	chicken_count=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(map[i][j]==2)
			{
				chicken[chicken_count][0]=i;
				chicken[chicken_count][1]=j;
				chicken_count++;
			}

	house=(int **)malloc(house_count*sizeof(int *));
	for(int i=0;i<house_count;i++)
		house[i]=(int *)malloc(2*sizeof(int));

	house_count=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(map[i][j]==1)
			{
				house[house_count][0]=i;
				house[house_count][1]=j;
				house_count++;
			}

	printf("%d\n", chicken_distance(chicken,house,chicken_count,house_count,M,-1,chicken_count-M));
	for(int i=0;i<house_count;i++)
		free(house[i]);
	free(house);
	for(int i=0;i<chicken_count;i++)
		free(chicken[i]);
	free(chicken);
	for(int i=0;i<N;i++)
		free(map[i]);
	free(map);
	return 0;
}