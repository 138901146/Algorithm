#include<stdio.h>

int N, queue[2000000], front=0, rear=0;

int main(void)
{
	scanf("%d", &N);
	getchar();

	while(N--)
	{
		char query[15];

		fgets(query,sizeof(query),stdin);

		if(query[0]=='p' && query[1]=='u')
		{
			int num;
			sscanf(query+4, "%d", &num);
			queue[rear++]=num;
		}
		else if(query[0]=='p')
			printf("%d\n", front==rear?-1:queue[front++]);
		else if(query[0]=='s')
			printf("%d\n", rear-front);
		else if(query[0]=='e')
			printf("%d\n", front==rear);
		else if(query[0]=='b')
			printf("%d\n", front==rear?-1:queue[rear-1]);
		else if(query[0]=='f')
			printf("%d\n", front==rear?-1:queue[front]);
	}

	return 0;
}