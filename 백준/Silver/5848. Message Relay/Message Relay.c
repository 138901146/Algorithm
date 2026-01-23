#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, F[1001]={0}, count=0;

	scanf("%d", &N);

	for(int i=1;i<=N;++i)
		scanf("%d", &F[i]);

	for(int i=1;i<=N;++i)
	{
		int current=i;
		bool visited[1001]={false};

		while(current&&!visited[current])
		{
			visited[current]=true;
			current=F[current];
		}

		count+=!current;
	}

	printf("%d", count);
	return 0;
}