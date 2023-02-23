#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int n, m, **chess=NULL, queen_move[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}}, knight_move[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}}, count, r, c;

	scanf("%d%d", &n, &m);
	chess=(int **)malloc(n*sizeof(int *));
	for(int i=0;i<n;i++)
		chess[i]=(int *)calloc(m,sizeof(int));

	scanf("%d", &count);
	for(int queen=0;queen<count;queen++)
	{
		scanf("%d%d", &r, &c);
		chess[r-1][c-1]=1;
	}

	scanf("%d", &count);
	for(int knight=0;knight<count;knight++)
	{
		scanf("%d%d", &r, &c);
		chess[r-1][c-1]=2;
	}

	scanf("%d", &count);
	for(int pawn=0;pawn<count;pawn++)
	{
		scanf("%d%d", &r, &c);
		chess[r-1][c-1]=3;
	}

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(chess[i][j]==1)
				for(int k=0;k<8;k++)
				{
					int l=1;

					while(i+l*queen_move[k][0]>=0 && i+l*queen_move[k][0]<n && j+l*queen_move[k][1]>=0 && j+l*queen_move[k][1]<m)
					{
						if(chess[i+l*queen_move[k][0]][j+l*queen_move[k][1]]==0 || chess[i+l*queen_move[k][0]][j+l*queen_move[k][1]]==-1)
							chess[i+l*queen_move[k][0]][j+l*queen_move[k][1]]=-1;
						else
							break;
						l++;
					}
				}
			else if(chess[i][j]==2)
				for(int k=0;k<8;k++)
					if(i+knight_move[k][0]>=0 && i+knight_move[k][0]<n && j+knight_move[k][1]>=0 && j+knight_move[k][1]<m)
						if(chess[i+knight_move[k][0]][j+knight_move[k][1]]==0)
							chess[i+knight_move[k][0]][j+knight_move[k][1]]=-1;

	count=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			count+=chess[i][j]==0;
		free(chess[i]);
	}
	free(chess);
	printf("%d\n", count);
	return 0;
}