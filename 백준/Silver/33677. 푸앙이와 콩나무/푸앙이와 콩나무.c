#include<stdio.h>
#include<malloc.h>

#define INF 9999999

int main(void)
{
	int N, *day=NULL, *water=NULL, *queue=NULL, front=0, rear=1;

	scanf("%d", &N);

	day=(int *)malloc((N+1)*sizeof(int));
	water=(int *)malloc((N+1)*sizeof(int));
	queue=(int *)malloc((N+1)*sizeof(int)<<1);

	for(int i=1;i<=N;++i)
		day[i]=water[i]=INF;
	day[0]=water[0]=queue[0]=0;

	while(front<rear)
	{
		if(queue[front]<N&&(day[queue[front]]+1<day[queue[front]+1]||day[queue[front]]+1==day[queue[front]+1]&&water[queue[front]]+1<water[queue[front]+1]))
		{
			day[queue[front]+1]=day[queue[front]]+1;
			water[queue[front]+1]=water[queue[front]]+1;
			queue[rear++]=queue[front]+1;
		}
		if(queue[front]*3<=N&&(day[queue[front]]+1<day[queue[front]*3]||day[queue[front]]+1==day[queue[front]*3]&&water[queue[front]]+3<water[queue[front]*3]))
		{
			day[queue[front]*3]=day[queue[front]]+1;
			water[queue[front]*3]=water[queue[front]]+3;
			queue[rear++]=queue[front]*3;
		}
		if((long long)queue[front]*queue[front]<=(long long)N&&(day[queue[front]]+1<day[queue[front]*queue[front]]||day[queue[front]]+1==day[queue[front]*queue[front]]&&water[queue[front]]+5<water[queue[front]*queue[front]]))
		{
			day[queue[front]*queue[front]]=day[queue[front]]+1;
			water[queue[front]*queue[front]]=water[queue[front]]+5;
			queue[rear++]=queue[front]*queue[front];
		}

		++front;
	}

	printf("%d %d", day[N], water[N]);
	free(queue);
	free(day);
	free(water);
	return 0;
}