#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool found=false;

bool check_sudoku(int **square)
{
	for(int i=0;i<9;i++)
	{
		bool row[9]={false, }, col[9]={false, };
		int check_row=0, check_col=0;

		for(int j=0;j<9;j++)
		{
			if(square[i][j]==0 || square[j][i]==0)
				return false;

			if(row[square[i][j]-1])
				return false;
			else
				row[square[i][j]-1]=true;

			if(col[square[j][i]-1])
				return false;
			else
				col[square[j][i]-1]=true;
		}

		for(int j=0;j<9;j++)
		{
			check_row+=row[j];
			check_col+=col[j];
		}

		if(check_row!=9 || check_col!=9)
			return false;
	}

	for(int i=0;i<9;i+=3)
		for(int j=0;j<9;j+=3)
		{
			bool small_square[9]={false, };
			int check_small=0;

			for(int k=0;k<3;k++)
				for(int l=0;l<3;l++)
					if(small_square[square[i+k][j+l]-1])
						return false;
					else
						small_square[square[i+k][j+l]-1]=true;

			for(int k=0;k<9;k++)
				check_small+=small_square[k];

			if(check_small!=9)
				return false;
		}

	return true;
}

void sudoku(int **square,int **to_fill,int count)
{
	if(found)
		return;

	if(count==0)
	{
		if(check_sudoku(square))
		{
			for(int i=0;i<9;i++)
			{
				for(int j=0;j<9;j++)
					printf("%d ", square[i][j]);
				printf("\n");
			}
			found=true;
		}
		return;
	}
	else
	{
		int x=to_fill[count-1][0], y=to_fill[count-1][1];
		bool row[9]={false, }, col[9]={false, }, nine[9]={false, };

		for(int i=0;i<9;i++)
		{
			if(square[i][y]>0)
			{
				if(row[square[i][y]-1])
					return;
				else
					row[square[i][y]-1]=true;
			}
			if(square[x][i]>0)
			{
				if(col[square[x][i]-1])
					return;
				else
					col[square[x][i]-1]=true;
			}
		}
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				if(square[x-x%3+i][y-y%3+j]>0)
				{
					if(nine[square[x-x%3+i][y-y%3+j]-1])
						return;
					else
						nine[square[x-x%3+i][y-y%3+j]-1]=true;
				}

		for(int i=0;i<9;i++)
		{
			if(!row[i] && !col[i] && !nine[i])
			{
				square[x][y]=i+1;
				sudoku(square,to_fill,count-1);
				square[x][y]=0;
			}
			if(found)
				return;
		}
		if(found)
			return;
	}
}

int main(void)
{
	int **square=(int **)malloc(9*sizeof(int *)), **to_fill=NULL, count=0, temp;

	for(int i=0;i<9;i++)
	{
		square[i]=(int  *)malloc(9*sizeof(int));

		for(int j=0;j<9;j++)
		{
			scanf("%d", &square[i][j]);
			count+=square[i][j]==0;
		}
	}

	to_fill=(int **)malloc(count*sizeof(int *));
	for(int i=0;i<count;i++)
		to_fill[i]=(int *)malloc(2*sizeof(int));

	temp=count;
	for(int i=8;i>=0;i--)
		for(int j=8;j>=0;j--)
			if(square[i][j]==0)
			{
				to_fill[--temp][0]=i;
				to_fill[temp][1]=j;
			}

	sudoku(square,to_fill,count);

	for(int i=0;i<count;i++)
		free(to_fill[i]);
	free(to_fill);
	for(int i=0;i<9;i++)
		free(square[i]);
	free(square);
	return 0;
}