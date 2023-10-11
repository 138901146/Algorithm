#include<stdio.h>

typedef struct
{
	int init, current;
}
HP;

int N, K, bullet[5], move[4][2]={{-1,0}, {0,-1}, {0,1}, {1,0}};

int simulate(HP target[8][8],int row,int shot,int score)
{
	if(shot==K)
		return score;

	int col=0, max=0;
	HP temp[8][8];

	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			temp[i][j]=target[i][j];

	while(col<N && !temp[row][col].current)
		++col;

	if(col<N)
	{
		if(temp[row][col].init>9)
		{
			score+=temp[row][col].init;
			temp[row][col].init=temp[row][col].current=0;
		}
		else
		{
			temp[row][col].current-=bullet[shot];
			if(temp[row][col].current<=0)
			{
				temp[row][col].current=0;
				score+=temp[row][col].init;
				int new=temp[row][col].init>>2;
				for(int i=0;i<4;++i)
				{
					row+=move[i][0];
					col+=move[i][1];

					if(row>=0 && row<N && col>=0 && col<N && temp[row][col].init==0)
						temp[row][col].init=temp[row][col].current=new;

					row-=move[i][0];
					col-=move[i][1];
				}

				temp[row][col].init=0;
			}
		}
	}

	for(int n=0;n<N;++n)
	{
		int next=simulate(temp,n,shot+1,score);
		max=next>max?next:max;
	}

	return max;
}

int main(void)
{
	HP target[8][8];
	int max=0;

	scanf("%d", &N);
	scanf("%d", &K);

	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
		{
			scanf("%d", &target[i][j].init);
			target[i][j].current=target[i][j].init;
		}

	for(int k=0;k<K;++k)
		scanf("%d", &bullet[k]);

	for(int n=0;n<N;++n)
	{
		int score=simulate(target,n,0,0);
		max=score>max?score:max;
	}

	printf("%d", max);
	return 0;
}