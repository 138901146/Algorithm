#include<stdio.h>
#include<stdbool.h>

char seat[5][6]={'\0', };
int count=0, choice[7], move[4][2]={{-1,0},{0,-1},{0,1},{1,0}};

void make_team(int current,int selected)
{
	if(selected==7)
	{
		int dasom=0, doyeon=0, connected=0, queue[7], front=0, rear=0;
		bool check[5][5]={false, }, visited[5][5]={false, };

		for(int i=0;i<7;++i)
		{
			check[choice[i]/5][choice[i]%5]=true;
			if(seat[choice[i]/5][choice[i]%5]=='S')
				++dasom;
			else
				++doyeon;
		}

		if(dasom<4)
			return;

		connected=1;
		visited[choice[0]/5][choice[0]%5]=true;

		queue[rear++]=choice[0];

		while(front<rear)
		{
			int r=queue[front]/5, c=queue[front]%5;

			for(int i=0;i<4;++i)
			{
				r+=move[i][0];
				c+=move[i][1];

				if(r>=0 && r<5 && c>=0 && c<5 && !visited[r][c] && check[r][c])
				{
					visited[r][c]=true;
					++connected;
					queue[rear++]=r*5+c;
				}

				r-=move[i][0];
				c-=move[i][1];
			}

			front++;
		}

		count+=connected==7;
		return;
	}

	for(int i=current+1;i<25;++i)
	{
		choice[selected]=i;
		make_team(i,selected+1);
	}
}

int main(void)
{
	for(int i=0;i<5;++i)
		scanf("%s", seat[i]);

	make_team(-1,0);

	printf("%d", count);
	return 0;
}