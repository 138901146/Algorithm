#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int abs(int N)
{
	return N<0?-N:N;
}

int queen(int *board,int current,int N)
{
	int count=0, *temp=calloc(N,sizeof(int));

	if(current==N)
	{
		free(temp);
		return 1;
	}

	for(int i=0;i<current;i++)
		temp[i]=board[i];

	for(int n=0;n<N;n++)
	{
		bool flag=true;

		for(int i=0;i<current;i++)
			if(board[i]==n || current-i==abs(n-board[i]))
			{
				flag=false;
				break;
			}

		if(flag)
		{
			temp[current]=n;
			count+=queen(temp,current+1,N);
		}
	}

	free(temp);
	return count;
}

int main(void)
{
	int N, *board=NULL;

	scanf("%d", &N);
	board=(int *)calloc(N,sizeof(int));

	printf("%d\n", queen(board,0,N));
	free(board);
	return 0;
}