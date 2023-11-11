#include<stdio.h>

typedef struct
{
	int r, c, cost;
}
tr;

tr pq[2097152];
int size;

tr get(void)
{
	int index=1;
	pq[0]=pq[1];
	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pq[left].cost<pq[right].cost?left:right:right==size?left:index;

		if(pq[index].cost<=pq[next].cost)
			break;

		tr temp=pq[index];
		pq[index]=pq[next];
		pq[next]=temp;
		index=next;
	}

	return pq[0];
}

void add(tr value)
{
	int index=size;
	pq[size++]=value;

	while(index>1)
	{
		int next=index>>1;

		if(pq[next].cost<=pq[index].cost)
			break;

		tr temp=pq[index];
		pq[index]=pq[next];
		pq[next]=temp;
		index=next;
	}
}

int main(void)
{
	int N, rupee[125][125], problem=0, move[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
	tr cave[125][125], next;

	scanf("%d", &N);

	for(int i=0;i<125;++i)
		for(int j=0;j<125;++j)
		{
			cave[i][j].r=i;
			cave[i][j].c=j;
		}

	while(N)
	{
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
			{
				scanf("%d", &rupee[i][j]);
				cave[i][j].cost=1000000;
			}
		cave[0][0].cost=rupee[0][0];
		pq[1]=cave[0][0];
		size=2;

		while(size>1)
		{
			tr next=get();

			if(next.cost!=cave[next.r][next.c].cost)
				continue;

			for(int i=0;i<4;++i)
			{
				next.r+=move[i][0];
				next.c+=move[i][1];

				if(next.r>=0 && next.r<N && next.c>=0 && next.c<N && cave[next.r][next.c].cost>next.cost+rupee[next.r][next.c])
				{
					cave[next.r][next.c].cost=next.cost+rupee[next.r][next.c];
					add(cave[next.r][next.c]);
				}

				next.r-=move[i][0];
				next.c-=move[i][1];
			}
		}

		printf("Problem %d: %d\n", ++problem, cave[N-1][N-1].cost);
		scanf("%d", &N);
	}

	return 0;
}