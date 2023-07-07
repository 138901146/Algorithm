#include<stdio.h>

int chess[15][15]={0, }, N;

int nqueen(int bottom)
{
	if(bottom==N)
		return 1;

	int count=0;

	for(int i=0;i<N;i++)
	{
		int check=0;
		chess[bottom][i]=1;

		for(int j=0;j<bottom;j++)
			if(chess[j][i])
			{
				check++;
				break;
			}

		if(check)
		{
			chess[bottom][i]=0;
			continue;
		}

		int y=bottom-1, x=i-1;

		while(y>=0 && x>=0)
		{
			if(chess[y][x])
			{
				check++;
				break;
			}
			y--;
			x--;
		}

		if(check)
		{
			chess[bottom][i]=0;
			continue;
		}

		y=bottom-1;
		x=i+1;

		while(y>=0 && x<N)
		{
			if(chess[y][x])
			{
				check++;
				break;
			}
			y--;
			x++;
		}

		if(check)
		{
			chess[bottom][i]=0;
			continue;
		}

		count+=nqueen(bottom+1);
		chess[bottom][i]=0;
	}

	return count;
}

int main(void)
{
	scanf("%d", &N);
	printf("%d\n", nqueen(0));
}