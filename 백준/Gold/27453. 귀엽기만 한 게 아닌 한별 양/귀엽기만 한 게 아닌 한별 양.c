#include<stdio.h>
#include<malloc.h>

#define INF 123456789

typedef struct
{
	int count[4], previous[4][2];
}
status;

int main(void)
{
	int N, M, K, *queue=NULL, front=0, rear=4, dr[4]={-1,0,1,0}, dc[4]={0,-1,0,1}, destination_r, destination_c, ans=INF;
	status **min=NULL;
	char **village=NULL;

	scanf("%d%d%d", &N, &M, &K);

	village=(char **)malloc(N*sizeof(char *));
	for(int r=0;r<N;++r)
	{
		village[r]=(char *)calloc(M+1,sizeof(char));
		scanf("%s", village[r]);
	}

	queue=(int *)malloc(N*M*sizeof(int)<<2);
	min=(status **)malloc(N*sizeof(status *));
	for(int r=0;r<N;++r)
	{
		min[r]=(status *)calloc(M,sizeof(status));
		for(int c=0;c<M;++c)
		{
			for(int i=0;i<4;++i)
				min[r][c].count[i]=INF;
			if(village[r][c]=='S')
				for(int i=0;i<4;++i)
				{
					min[r][c].count[i]=0;
					queue[i]=r<<12|c<<2|i;
					village[r][c]='0';
				}
			else if(village[r][c]=='H')
			{
				destination_r=r;
				destination_c=c;
				village[r][c]='0';
			}
		}
	}

	while(front<rear&&min[destination_r][destination_c].count[0]==INF&&min[destination_r][destination_c].count[1]==INF&&min[destination_r][destination_c].count[2]==INF&&min[destination_r][destination_c].count[3]==INF)
	{
		int r=queue[front]>>12, c=(queue[front]>>2)&1023, direction=queue[front]&3;

		for(int i=0;i<4;++i)
		{
			int next_r=r+dr[i], next_c=c+dc[i];

			if(next_r<0||N<=next_r||next_c<0||M<=next_c||((direction&1)==(i&1)&&i!=direction)||village[next_r][next_c]=='X')
				continue;
			else if(K<min[r][c].previous[direction][0]+min[r][c].previous[direction][1]+village[next_r][next_c]-'0'||min[next_r][next_c].count[i]<=min[r][c].count[direction]+1)
				continue;

			min[next_r][next_c].count[i]=min[r][c].count[direction]+1;
			min[next_r][next_c].previous[i][0]=min[r][c].previous[direction][1];
			min[next_r][next_c].previous[i][1]=village[next_r][next_c]-'0';
			queue[rear++]=next_r<<12|next_c<<2|i;
		}

		++front;
	}

	for(int i=0;i<4;++i)
		ans=min[destination_r][destination_c].count[i]<ans?min[destination_r][destination_c].count[i]:ans;

	printf("%d", ans==INF?-1:ans);

	for(int r=0;r<N;++r)
	{
		free(village[r]);
		free(min[r]);
	}
	free(village);
	free(min);
	free(queue);
	return 0;
}