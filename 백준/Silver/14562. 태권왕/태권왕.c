#include<stdio.h>
#include<stdbool.h>
#include<memory.h>

int count[1001][1001], queue[1000001];

int main(void)
{
	int C;

	scanf("%d", &C);

	while(C--)
	{
		bool found=false;
		int S, T, front=0, rear=1;

		scanf("%d%d", &S, &T);

		memset(count,0,1002001*sizeof(int));
		count[S][T]=1;
		queue[0]=S<<10|T;

		while(!found&&front<rear)
		{
			int s=queue[front]>>10, t=queue[front]&1023;

			if((s<<1)<=t+3&&!count[s<<1][t+3])
			{
				count[s<<1][t+3]=count[s][t]+1;
				queue[rear++]=(s<<11|t)+3;
				if((s<<1)==t+3)
				{
					printf("%d\n", count[s][t]);
					found=true;
					break;
				}
			}
			if(s+1<=t&&!count[s+1][t])
			{
				count[s+1][t]=count[s][t]+1;
				queue[rear++]=(s+1<<10)|t;
				if(s+1==t)
				{
					printf("%d\n", count[s][t]);
					found=true;
					break;
				}
			}

				++front;
		}
	}

	return 0;
}