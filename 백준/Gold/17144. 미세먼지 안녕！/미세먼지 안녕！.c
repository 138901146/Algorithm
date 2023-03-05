#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int R, C, T, ***house=NULL, air_purifier=-1, sum=2;

	scanf("%d%d%d", &R, &C, &T);
	house=(int ***)malloc(R*sizeof(int **));
	for(int r=0;r<R;r++)
	{
		house[r]=(int **)malloc(C*sizeof(int *));
		for(int c=0;c<C;c++)
		{
			house[r][c]=(int *)calloc(2,sizeof(int));
			scanf("%d", &house[r][c][0]);
			if(house[r][c][0]==-1)
			{
				house[r][c][1]=-1;
				if(air_purifier==-1)
					air_purifier=r;
			}
		}
	}

	for(int t=0;t<T;t++)
	{
		int current=t%2, next=(t+1)%2;

		for(int r=0;r<R;r++)
			for(int c=0;c<C;c++)
				if(house[r][c][current]>0)
				{
					int moved=0;
					if(r>0 && house[r-1][c][current]!=-1)
					{
						moved+=house[r][c][current]/5;
						house[r-1][c][next]+=house[r][c][current]/5;
					}
					if(r<R-1 && house[r+1][c][current]!=-1)
					{
						moved+=house[r][c][current]/5;
						house[r+1][c][next]+=house[r][c][current]/5;
					}
					if(c>0 && house[r][c-1][current]!=-1)
					{
						moved+=house[r][c][current]/5;
						house[r][c-1][next]+=house[r][c][current]/5;
					}
					if(c<C-1 && house[r][c+1][current]!=-1)
					{
						moved+=house[r][c][current]/5;
						house[r][c+1][next]+=house[r][c][current]/5;
					}
					house[r][c][next]+=house[r][c][current]-moved;
					house[r][c][current]=0;
				}
		
		for(int r=air_purifier-1;r>0;r--)
			house[r][0][next]=house[r-1][0][next];
		for(int c=0;c<C-1;c++)
			house[0][c][next]=house[0][c+1][next];
		for(int r=0;r<air_purifier;r++)
			house[r][C-1][next]=house[r+1][C-1][next];
		for(int c=C-1;c>1;c--)
			house[air_purifier][c][next]=house[air_purifier][c-1][next];
		house[air_purifier][1][next]=0;
		air_purifier++;
		for(int r=air_purifier+1;r<R-1;r++)
			house[r][0][next]=house[r+1][0][next];
		for(int c=0;c<C-1;c++)
			house[R-1][c][next]=house[R-1][c+1][next];
		for(int r=R-1;r>air_purifier;r--)
			house[r][C-1][next]=house[r-1][C-1][next];
		for(int c=C-1;c>1;c--)
			house[air_purifier][c][next]=house[air_purifier][c-1][next];
		house[air_purifier][1][next]=0;
		air_purifier--;
	}

	for(int r=0;r<R;r++)
		for(int c=0;c<C;c++)
			sum+=house[r][c][T%2];

	printf("%d\n", sum);
	for(int r=0;r<R;r++)
	{
		for(int c=0;c<C;c++)
			free(house[r][c]);
		free(house[r]);
	}
	free(house);
	return 0;
}