#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int vertex, time;
}
node;

typedef struct
{
	int src, dst, time;
}
edge;

node *pq=NULL;
int size=1;

node get(void)
{
	int index=1;

	pq[0]=pq[1];
	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pq[left].time<pq[right].time?left:right:right==size?left:index;

		if(pq[index].time<=pq[next].time)
			break;

		node temp=pq[index];
		pq[index]=pq[next];
		pq[next]=temp;
		index=next;
	}

	return pq[0];
}

void add(node value)
{
	int index=size;

	pq[size++]=value;

	while(1<index)
	{
		int next=index>>1;

		if(pq[next].time<=pq[index].time)
			break;

		pq[0]=pq[index];
		pq[index]=pq[next];
		pq[next]=pq[0];
		index=next;
	}
}

int main(void)
{
	int N, E, T, M, *cell_count=NULL, escape=0;
	edge *connection=NULL;
	node **cell=NULL, *path=NULL;

	scanf("%d", &N);
	scanf("%d", &E);
	scanf("%d", &T);
	scanf("%d", &M);

	if(N<E)
	{
		printf("0");
		return 0;
	}

	cell=(node **)malloc((N+1)*sizeof(node *));
	cell_count=(int *)calloc(N+1,sizeof(int));
	connection=(edge *)malloc(M*sizeof(edge));
	path=(node *)malloc((N+1)*sizeof(node));

	for(int m=0;m<M;++m)
	{
		scanf("%d%d%d", &connection[m].src, &connection[m].dst, &connection[m].time);
		++cell_count[connection[m].dst];
	}

	for(int n=1;n<=N;++n)
	{
		cell[n]=(node *)malloc(cell_count[n]*sizeof(node));
		path[n].vertex=n;
		path[n].time=999999999;
		cell_count[n]=0;
	}

	for(int m=0;m<M;++m)
	{
		cell[connection[m].dst][cell_count[connection[m].dst]].vertex=connection[m].src;
		cell[connection[m].dst][cell_count[connection[m].dst]++].time=connection[m].time;
	}
	free(connection);

	pq=(node *)malloc(10000*sizeof(node));
	path[E].time=0;
	add(path[E]);

	while(1<size)
	{
		node current=get();
		int id=current.vertex;

		if(path[id].time!=current.time)
			continue;

		for(int i=0;i<cell_count[id];++i)
		{
			int next=cell[id][i].vertex;

			if(current.time+cell[id][i].time<path[next].time)
			{
				path[next].time=current.time+cell[id][i].time;
				add(path[next]);
			}
		}
	}

	for(int n=1;n<=N;++n)
	{
		escape+=path[n].time<=T;
		free(cell[n]);
	}
	printf("%d", escape);
	free(cell);
	free(cell_count);
	free(path);
	free(pq);
	return 0;
}