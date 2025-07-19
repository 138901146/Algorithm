#include<stdio.h>

int main(void)
{
	int N, number[10001], b, count[10001], queue[10000], front=0, rear=1;

	scanf("%d", &N);
	for(int n=1;n<=N;++n)
	{
		scanf("%d", &number[n]);
		count[n]=-1;
	}

	scanf("%d%d", &queue[0], &b);
	count[queue[0]]=0;

	while(count[b]==-1&&front<rear)
	{
		for(int next=queue[front];next<=N;next+=number[queue[front]])
			if(count[next]==-1)
			{
				count[next]=count[queue[front]]+1;
				queue[rear++]=next;
			}
		for(int next=queue[front];0<next;next-=number[queue[front]])
			if(count[next]==-1)
			{
				count[next]=count[queue[front]]+1;
				queue[rear++]=next;
			}

		++front;
	}

	printf("%d", count[b]);
	return 0;
}