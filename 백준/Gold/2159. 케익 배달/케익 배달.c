#include<stdio.h>

#define INF 90000000000

int abs(int x)
{
	return x<0?-x:x;
}

int main(void)
{
	int N, restaurant_x, restaurant_y, X[2], Y[2], dx[5]={0,-1,0,1,0}, dy[5]={0,0,1,0,-1}, current=0, previous=1;
	long long deliver[2][5], min=INF;

	scanf("%d", &N);
	scanf("%d%d", &X[0], &Y[0]);

	scanf("%d%d", &X[1], &Y[1]);
	for(int i=0;i<5;++i)
		deliver[1][i]=abs(X[1]+dx[i]-X[0])+abs(Y[1]+dy[i]-Y[0]);

	while(--N)
	{
		scanf("%d%d", &X[current], &Y[current]);

		for(int i=0;i<5;++i)
		{
			int r=X[current]+dx[i], c=Y[current]+dy[i];
			deliver[current][i]=INF;

			for(int j=0;j<5;++j)
			{
				long long distance=deliver[previous][j]+abs(X[previous]+dx[j]-r)+abs(Y[previous]+dy[j]-c);
				deliver[current][i]=deliver[current][i]<distance?deliver[current][i]:distance;
			}
		}

		current^=1;
		previous^=1;
	}

	for(int i=0;i<5;++i)
		min=deliver[previous][i]<min?deliver[previous][i]:min;

	printf("%lld", min);
	return 0;
}