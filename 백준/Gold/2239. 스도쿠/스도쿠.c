#include<stdio.h>
#include<stdbool.h>

bool done=false;
int count=0, x[81], y[81], sudoku[9][9];

bool check_sudoku()
{
	for(int i=0;i<9;i++)
	{
		bool check_y[9]={false, }, check_x[9]={false, };
		for(int j=0;j<9;j++)
			if(sudoku[j][i]<1 || sudoku[i][j]<1 || check_y[sudoku[j][i]-1] || check_x[sudoku[i][j]-1])
				return false;
			else
				check_y[sudoku[j][i]-1]=check_x[sudoku[i][j]-1]=true;
	}

	for(int i=0;i<9;i+=3)
		for(int j=0;j<9;j+=3)
		{
			bool check_nine[9]={false, };
			for(int k=0;k<3;k++)
				for(int l=0;l<3;l++)
					if(sudoku[i+k][j+l]<1 ||  check_nine[sudoku[i+k][j+l]-1])
						return false;
					else
						check_nine[sudoku[i+k][j+l]-1]=true;
		}

	return true;
}

void simulate(int current)
{
	if(current==count)
	{
		done=check_sudoku();
		return;
	}

	bool able[10];
	int current_x=x[current], current_y=y[current];

	for(int i=1;i<10;i++)
		able[i]=true;

	for(int i=0;i<9;i++)
		able[sudoku[i][current_x]]=able[sudoku[current_y][i]]=false;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			able[sudoku[current_y-(current_y%3)+i][current_x-(current_x%3)+j]]=false;

	for(int i=1;i<10;i++)
		if(done)
			return;
		else if(able[i])
		{
			sudoku[current_y][current_x]=i;
			simulate(current+1);
			if(!done)
				sudoku[current_y][current_x]=0;
		}
}

int main(void)
{
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
		{
			scanf("%1d", &sudoku[i][j]);
			if(sudoku[i][j]==0)
			{
				y[count]=i;
				x[count++]=j;
			}
		}

	simulate(0);

	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			printf("%d", sudoku[i][j]);
		printf("\n");
	}

	return 0;
}