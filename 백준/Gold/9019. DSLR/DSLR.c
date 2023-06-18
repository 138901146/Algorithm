#include<stdio.h>

int main(void)
{
	int T, A, B, queue[10000], current, D, S, L, R, d[4], next[4];
	char order[10000];

	scanf("%d", &T);
	for(int t=0;t<T;t++)
	{
		int state[10000]={0, }, front=0, rear=0, length=0;

		scanf("%d%d", &A, &B);

		queue[rear++]=A;
		state[A]=1;

		while(state[B]==0)
		{
			current=queue[front];

			next[0]=(current<<1)%10000;
			next[1]=(current+9999)%10000;
			for(int i=3;i>=0;i--)
			{
				d[i]=current%10;
				current/=10;
			}
			next[2]=1000*d[1]+100*d[2]+10*d[3]+d[0];
			next[3]=1000*d[3]+100*d[0]+10*d[1]+d[2];

			current=queue[front];

			for(int i=0;i<4;i++)
				if(state[next[i]]==0)
				{
					queue[rear++]=next[i];
					state[next[i]]=i*10000+current;
				}
			front++;
		}

		current=B;
		while(current!=A)
		{
			switch(state[current]/10000)
			{
				case 0:
					order[length++]='D';
					break;
				case 1:
					order[length++]='S';
					break;
				case 2:
					order[length++]='L';
					break;
				case 3:
					order[length++]='R';
					break;
			}

			current=state[current]%10000;
		}

		for(int i=length-1;i>=0;i--)
			printf("%c", order[i]);
		printf("\n");
	}

	return 0;
}