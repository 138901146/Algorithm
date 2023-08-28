#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int target, distance;
}
Vertex;

typedef struct
{
	int from, to, distance;
}
Edge;

int size=1;
Vertex *pq=NULL;

Vertex get(void)
{
	int index=1;

	pq[0]=pq[1];
	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pq[left].distance<pq[right].distance?left:right:right==size?left:index;

		if(pq[index].distance<=pq[next].distance)
			break;

		Vertex temp=pq[index];
		pq[index]=pq[next];
		pq[next]=temp;
		index=next;
	}

	return pq[0];
}

void add(Vertex value)
{
	int index=size;

	pq[size++]=value;

	while(index>1)
	{
		int next=index>>1;

		if(pq[next].distance<=pq[index].distance)
			break;

		Vertex temp=pq[index];
		pq[index]=pq[next];
		pq[next]=temp;
		index=next;
	}
}

int main(void)
{
	int V, E, P, *vertex_count=NULL, *distance=NULL, gunwoo, masan;
	Edge *edge=NULL;
	Vertex **vertex=NULL;

	scanf("%d%d%d", &V, &E, &P);
	vertex_count=(int *)calloc(V+1,sizeof(int));
	edge=(Edge *)malloc(E*sizeof(Edge));
	vertex=(Vertex **)malloc((V+1)*sizeof(Vertex *));

	for(int e=0;e<E;++e)
	{
		scanf("%d%d%d", &edge[e].from, &edge[e].to, &edge[e].distance);
		vertex_count[edge[e].from]++;
		vertex_count[edge[e].to]++;
	}

	for(int v=1;v<=V;++v)
	{
		vertex[v]=(Vertex *)malloc(vertex_count[v]*sizeof(Vertex));
		vertex_count[v]=0;
	}

	for(int e=0;e<E;++e)
	{
		vertex[edge[e].from][vertex_count[edge[e].from]].target=edge[e].to;
		vertex[edge[e].from][vertex_count[edge[e].from]++].distance=edge[e].distance;
		vertex[edge[e].to][vertex_count[edge[e].to]].target=edge[e].from;
		vertex[edge[e].to][vertex_count[edge[e].to]++].distance=edge[e].distance;
	}
	free(edge);

	pq=(Vertex *)malloc((V<<2)*sizeof(Vertex));
	distance=(int *)malloc((V+1)*sizeof(int));
	distance[1]=0;
	for(int v=2;v<=V;++v)
		distance[v]=100000000;
	Vertex temp={1,0};

	add(temp);

	while(size>1)
	{
		Vertex next=get();
		int index=next.target;

		for(int i=0;i<vertex_count[index];++i)
			if(distance[vertex[index][i].target]>distance[index]+vertex[index][i].distance)
			{
				distance[vertex[index][i].target]=distance[index]+vertex[index][i].distance;
				temp.target=vertex[index][i].target;
				temp.distance=distance[vertex[index][i].target];
				add(temp);
			}
	}
	gunwoo=distance[P];
	masan=distance[V];

	for(int v=1;v<=V;++v)
		distance[v]=100000000;
	distance[P]=0;
	temp.target=P;
	temp.distance=0;

	add(temp);

	while(size>1)
	{
		Vertex next=get();
		int index=next.target;

		for(int i=0;i<vertex_count[index];++i)
			if(distance[vertex[index][i].target]>distance[index]+vertex[index][i].distance)
			{
				distance[vertex[index][i].target]=distance[index]+vertex[index][i].distance;
				temp.target=vertex[index][i].target;
				temp.distance=distance[vertex[index][i].target];
				add(temp);
			}
	}

	printf("%s\n", gunwoo+distance[V]==masan?"SAVE HIM":"GOOD BYE");
	for(int v=1;v<=V;++v)
		free(vertex[v]);
	free(vertex);
	free(distance);
	free(pq);
	free(vertex_count);
	return 0;
}