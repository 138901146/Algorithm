#include<stdio.h>
#include<stdbool.h>

char field[12][7]={0};

void gravity(void)
{
	for(int c=0;c<6;++c)
	{
		int rear=0;
		char queue[12];

		for(int r=11;0<=r;--r)
		{
			if(field[r][c]!='.')
				queue[rear++]=field[r][c];
			field[r][c]='.';
		}

		for(int front=0;front<rear;++front)
			field[11-front][c]=queue[front];
	}
}

bool bomb(void)
{
	int dr[4]={-1,0,0,1}, dc[4]={0,-1,1,0}, queue[72];
	bool visited[12][6]={false}, exploded=false;

	for(int r=0;r<12;++r)
		for(int c=0;c<6;++c)
			if(field[r][c]!='.'&&!visited[r][c])
			{
				int front=0, rear=1;

				visited[r][c]=true;
				queue[0]=r<<3|c;

				while(front<rear)
				{
					int current_r=queue[front]>>3, current_c=queue[front]&7;

					for(int i=0;i<4;++i)
					{
						int next_r=current_r+dr[i], next_c=current_c+dc[i];

						if(next_r<0||11<next_r||next_c<0||5<next_c||visited[next_r][next_c]||field[next_r][next_c]!=field[r][c])
							continue;

						visited[next_r][next_c]=true;
						queue[rear++]=next_r<<3|next_c;
					}

					++front;
				}

				if(3<rear)
				{
					exploded=true;
					for(front=0;front<rear;++front)
						field[queue[front]>>3][queue[front]&7]='.';
				}
			}

	return exploded;
}

int main(void)
{
	bool puyo=true;
	int count=0;

	for(int r=0;r<12;++r)
		scanf("%s", field[r]);

	while(puyo)
	{
		gravity();
		puyo=bomb();
		count+=puyo;
	}

	printf("%d", count);
	return 0;
}