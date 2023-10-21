#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int id, distance;
}
vertex_info;

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:-1;
}

vertex_info *pq=NULL;
int size=1;

vertex_info get(void)
{
	int index=1;

	pq[0]=pq[1];
	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pq[left].distance<pq[right].distance?left:right:right==size?left:index;

		if(pq[index].distance<=pq[next].distance)
			break;

		vertex_info temp=pq[index];
		pq[index]=pq[next];
		pq[next]=temp;
		index=next;
	}

	return pq[0];
}

void add(vertex_info value)
{
	int index=size;

	pq[size++]=value;

	while(index>1)
	{
		int next=index>>1;

		if(pq[index].distance>=pq[next].distance)
			break;

		vertex_info temp=pq[index];
		pq[index]=pq[next];
		pq[next]=temp;
		index=next;
	}
}


int main(void)
{
	int n, m, *vertex_count=NULL, **edge=NULL, p, q, *house=NULL, *distance=NULL, convinence_store, id=0;
	vertex_info **vertex=NULL;

	scanf("%d%d", &n, &m);
	vertex_count=(int *)calloc(n+1,sizeof(int));
	vertex=(vertex_info **)malloc((n+1)*sizeof(vertex_info *));
	edge=(int **)malloc(m*sizeof(int *));

	for(int i=0;i<m;++i)
	{
		edge[i]=(int *)malloc(3*sizeof(int));

		for(int j=0;j<2;++j)
		{
			scanf("%d", &edge[i][j]);
			++vertex_count[edge[i][j]];
		}
		scanf("%d", &edge[i][2]);
	}

	for(int i=1;i<=n;++i)
	{
		vertex[i]=(vertex_info *)malloc(vertex_count[i]*sizeof(vertex_info));
		vertex_count[i]=0;
	}

	for(int i=0;i<m;++i)
	{
		for(int j=0;j<2;++j)
		{
			vertex[edge[i][j]][vertex_count[edge[i][j]]].id=edge[i][j^1];
			vertex[edge[i][j]][vertex_count[edge[i][j]]++].distance=edge[i][2];
		}
		free(edge[i]);
	}
	free(edge);

	scanf("%d%d", &p, &q);
	house=(int *)malloc(p*sizeof(int));

	for(int i=0;i<p;++i)
		scanf("%d", &house[i]);
	qsort((void *)house,(size_t)p,sizeof(int),compare);

	distance=(int *)malloc((n+1)*sizeof(int));
	for(int i=1;i<=n;++i)
		distance[i]=1000000000;

	pq=(vertex_info *)malloc((n<<5)*sizeof(vertex_info));
	while(q--)
	{
		scanf("%d", &convinence_store);
		distance[convinence_store]=0;
		vertex_info temp={convinence_store,0};
		pq[size++]=temp;
	}

	while(size>1)
	{
		vertex_info next=get();

		if(next.distance==distance[next.id])
			for(int i=0;i<vertex_count[next.id];++i)
				if(distance[vertex[next.id][i].id]>next.distance+vertex[next.id][i].distance)
				{
					vertex_info temp;
					temp.distance=distance[vertex[next.id][i].id]=next.distance+vertex[next.id][i].distance;
					temp.id=vertex[next.id][i].id;
					add(temp);
				}
	}

	for(int i=1;i<p;++i)
		id=distance[house[i]]<distance[house[id]]?i:id;

	printf("%d", house[id]);
	free(pq);
	free(house);
	free(distance);
	free(vertex_count);
	while(n)
		free(vertex[n--]);
	free(vertex);
	return 0;
}