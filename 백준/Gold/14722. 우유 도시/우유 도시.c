#include<stdio.h>

int bigger(int x,int y)
{
	return x<y?y:x;
}

int main(void)
{
	int N, id, milk[2][1001][3]={0}, current=1, previous=0, max=0;

	scanf("%d", &N);

	for(int n=0;n<N;++n, current^=1, previous^=1)
	{
		for(int i=1;i<=N;++i)
			for(int j=0;j<3;++j)
				milk[current][i][j]=0;

		for(int i=1;i<=N;++i)
		{
			scanf("%d", &id);

			for(int j=0;j<3;++j)
			{
				milk[current][i][j]=bigger(milk[current][i][j],milk[current][i-1][j]);
				milk[current][i][j]=bigger(milk[current][i][j],milk[previous][i][j]);
			}

			if(id)
			{
				if(milk[current][i-1][id-1])
					milk[current][i][id]=bigger(milk[current][i][id],milk[current][i-1][id-1]+1);
				if(milk[previous][i][id-1])
					milk[current][i][id]=bigger(milk[current][i][id],milk[previous][i][id-1]+1);
			}
			else
			{
				milk[current][i][0]=bigger(milk[current][i][0],milk[current][i-1][2]+1);
				milk[current][i][0]=bigger(milk[current][i][0],milk[previous][i][2]+1);
			}
		}
	}

	for(int i=0;i<3;++i)
		max=bigger(max,milk[previous][N][i]);

	printf("%d", max);
	return 0;
}