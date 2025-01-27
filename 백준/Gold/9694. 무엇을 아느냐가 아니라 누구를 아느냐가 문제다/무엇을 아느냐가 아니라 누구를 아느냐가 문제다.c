#include<stdio.h>

#define INF 99

typedef struct
{
	int id, last, distance;
}
vertex;

typedef struct
{
	int id, distance;
}
edge;

int size;
edge pq[400];

edge convert(vertex origin)
{
	edge new={origin.id, origin.distance};

	return new;
}

edge get(void)
{
	int index=1;

	pq[0]=pq[1];
	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pq[left].distance<pq[right].distance?left:right:right==size?left:index;

		if(pq[index].distance<=pq[next].distance)
			break;

		pq[size]=pq[index];
		pq[index]=pq[next];
		pq[next]=pq[size];
		index=next;
	}

	return pq[0];
}

void add(edge node)
{
	int index=size;

	pq[size++]=node;

	while(1<index)
	{
		int next=index>>1;

		if(pq[next].distance<=pq[index].distance)
			break;

		pq[0]=pq[index];
		pq[index]=pq[next];
		pq[next]=pq[0];
		index=next;
	}
}

int main(void)
{
	int T, N, M, x, y, z;
	vertex relationship[20];
	edge adjacent_list[20][20];

	scanf("%d", &T);

	for(int t=1;t<=T;++t)
	{
		int adjacent_list_count[20]={0}, current=0;

		scanf("%d%d", &N, &M);

		size=2;

		for(int i=0;i<M;++i)
		{
			relationship[i].id=i;
			relationship[i].distance=INF;
		}
		relationship[M-1].distance=0;

		while(N--)
		{
			scanf("%d%d%d", &x, &y, &z);
			adjacent_list[y][adjacent_list_count[y]].id=x;
			adjacent_list[x][adjacent_list_count[x]].id=y;
			adjacent_list[y][adjacent_list_count[y]++].distance=adjacent_list[x][adjacent_list_count[x]++].distance=z;
		}

		pq[1].id=M-1;
		pq[1].distance=0;
		while(1<size)
		{
			int id=pq[1].id, distance=pq[1].distance;
			get();

			if(distance!=relationship[id].distance)
				continue;

			for(int i=0;i<adjacent_list_count[id];++i)
			{
				int next=adjacent_list[id][i].id;

				if(distance+adjacent_list[id][i].distance<relationship[next].distance)
				{
					relationship[next].distance=distance+adjacent_list[id][i].distance;
					relationship[next].last=id;
					add(convert(relationship[next]));
				}
			}
		}

		printf("Case #%d: ", t);
		if(relationship[0].distance==INF)
		{
			printf("-1\n");
			continue;
		}

		while(current!=M-1)
		{
			printf("%d ", current);
			current=relationship[current].last;
		}
		printf("%d\n", M-1);
	}

	return 0;
}