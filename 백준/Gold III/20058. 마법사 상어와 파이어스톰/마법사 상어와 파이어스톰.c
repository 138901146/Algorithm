#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, A[64][64][2], queue[4096], current=0, next=1, Q, sum=0, max=0, move[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
	bool visited[64][64]={false};

	scanf("%d%d", &N, &Q);

	N=1<<N;
	for(int r=0;r<N;++r)
		for(int c=0;c<N;++c)
			scanf("%d", &A[r][c][0]);

	while(Q--)
	{
		int L, rear=0;

		scanf("%d", &L);
		L=1<<L;

		for(int i=0;i<N;i+=L)
			for(int j=0;j<N;j+=L)
				for(int r=0;r<L;++r)
					for(int c=0;c<L;++c)
						A[i+c][j+L-1-r][next]=A[i+r][j+c][current];

		for(int r=0;r<N;++r)
			for(int c=0;c<N;++c)
				if(A[r][c][next])
				{
					int count=0;

					for(int i=0;i<4;++i)
					{
						int dr=r+move[i][0], dc=c+move[i][1];

						if(dr<0 || N<=dr || dc<0 || N<=dc || !A[dr][dc][next])
							continue;
						++count;
					}

					if(count<3)
						queue[rear++]=r<<6|c;
				}

		for(int front=0;front<rear;++front)
			--A[queue[front]>>6][queue[front]&63][next];

		current^=1;
		next^=1;
	}

	for(int r=0;r<N;++r)
		for(int c=0;c<N;++c)
		{
			sum+=A[r][c][current];

			if(!visited[r][c] && A[r][c][current])
			{
				int front=0, rear=1;

				visited[r][c]=true;
				queue[0]=r<<6|c;

				while(front<rear)
				{
					int cur_r=queue[front]>>6, cur_c=queue[front]&63;

					for(int i=0;i<4;++i)
					{
						int dr=cur_r+move[i][0], dc=cur_c+move[i][1];

						if(dr<0 || N<=dr || dc<0 || N<=dc || visited[dr][dc] || !A[dr][dc][current])
							continue;

						visited[dr][dc]=true;
						queue[rear++]=dr<<6|dc;
					}

					++front;
				}

				max=max<rear?rear:max;
			}
		}

	printf("%d\n%d", sum, max);
	return 0;
}