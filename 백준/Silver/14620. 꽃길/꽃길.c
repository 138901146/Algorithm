#include<stdio.h>

int N, G[10][10], min=5000, dr[5]={-1,0,0,0,1}, dc[5]={0,-1,0,1,0}, r[3], c[3];

void simulate(int current)
{
	if(current==3)
	{
		int price=0;

		for(int i=0;i<3;++i)
			for(int j=0;j<5;++j)
				price+=G[r[i]+dr[j]][c[i]+dc[j]];

		min=price<min?price:min;
		return;
	}

	for(int x=1;x<N-1;++x)
		for(int y=1;y<N-1;++y)
		{
			int plantable=1;

			r[current]=y;
			c[current]=x;

			for(int i=0;i<current&&plantable;++i)
				for(int j=0;j<5&&plantable;++j)
					for(int k=0;k<5&&plantable;++k)
						if(r[i]+dr[j]==r[current]+dr[k] && c[i]+dc[j]==c[current]+dc[k])
							plantable=0;

			if(plantable)
				simulate(current+1);
		}
}

int main(void)
{
	scanf("%d", &N);

	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			scanf("%d", &G[i][j]);

	simulate(0);

	printf("%d", min);
	return 0;
}