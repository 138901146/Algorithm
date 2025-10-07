#include<stdio.h>

#define INF 999

int main(void)
{
	int N, M, x, y, u, v, min[101], queue[200], front=0, rear=1, jump[101]={0,};

	scanf("%d%d", &N, &M);
	while(N--)
	{
		scanf("%d%d", &x, &y);
		jump[x]=y;
	}
	while(M--)
	{
		scanf("%d%d", &u, &v);
		jump[u]=v;
	}

	for(int i=2;i<101;++i)
		min[i]=INF;
	queue[0]=1;
	min[1]=0;
	while(min[100]==INF)
	{
		int current=queue[front++];

		for(int dice=1;dice<7&&current+dice<101;++dice)
			if(!jump[current+dice]&&min[current]+1<min[current+dice])
			{
				min[current+dice]=min[current]+1;
				queue[rear++]=current+dice;
			}
			else if(jump[current+dice]&&min[current]+1<min[jump[current+dice]])
			{
				min[jump[current+dice]]=min[current]+1;
				queue[rear++]=jump[current+dice];
			}
	}

	printf("%d", min[100]);
	return 0;
}