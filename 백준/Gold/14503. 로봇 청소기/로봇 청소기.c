#include<stdio.h>

int main(void)
{
	int N, M, r, c, d, room[50][50], count=0, move[4][2]={{-1,0}, {0,1}, {1,0}, {0,-1}};

	scanf("%d%d", &N, &M);
	scanf("%d%d%d", &r, &c, &d);

	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			scanf("%d", &room[i][j]);

	while(1)
	{
		if(!room[r][c])
		{
			room[r][c]=2;
			++count;
		}

		for(int i=0;i<4;++i)
		{
			d=(d+3)&3;
			r+=move[d][0];
			c+=move[d][1];

			if(r>=0 && r<N && c>=0 && c<M && !room[r][c])
				break;

			r-=move[d][0];
			c-=move[d][1];
		}

		if(!room[r][c])
			continue;

		r-=move[d][0];
		c-=move[d][1];

		if(r<0 || r>=N || c<0 || c>=M || room[r][c]==1)
			break;
	}

	printf("%d", count);
	return 0;
}