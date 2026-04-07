#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, Z, M, x, K=0;
	bool obstacle[1001]={false};

	scanf("%d%d%d", &N, &Z, &M);

	while(M--)
	{
		scanf("%d", &x);
		obstacle[x]=true;
	}

	while(++K)
	{
		int current=1;
		bool visited[1001]={false};

		while(current!=Z&&!visited[current])
		{
			visited[current]=true;
			current+=K;

			if(N<current)
				current%=N;

			if(obstacle[current])
				break;
		}

		if(current==Z)
		{
			printf("%d", K);
			return 0;
		}
	}

	return 0;
}