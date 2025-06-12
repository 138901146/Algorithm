#include<stdio.h>

typedef struct
{
	int src, dst, cost;
}
node;

node pq[1000000];
int size=1, parent[1000];

node get(void)
{
	int index=1;

	pq[0]=pq[1];
	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pq[left].cost<pq[right].cost?left:right:right==size?left:index;

		if(pq[index].cost<=pq[next].cost)
			break;

		node temp=pq[index];
		pq[index]=pq[next];
		pq[next]=temp;
		index=next;
	}

	return pq[0];
}

void add(node data)
{
	int index=size;

	pq[size++]=data;

	while(1<index)
	{
		int next=index>>1;

		if(pq[next].cost<=pq[index].cost)
			break;

		pq[0]=pq[index];
		pq[index]=pq[next];
		pq[next]=pq[0];
		index=next;
	}
}

int find_parent(int current)
{
	if(parent[current]==current)
		return current;

	return parent[current]=find_parent(parent[current]);
}

void union_parent(int x,int y)
{
	int parent_x=find_parent(x), parent_y=find_parent(y);

	if(parent_x!=parent_y)
		parent[parent_x]=parent_y;
}

int main(void)
{
	int N, C, connected=0;
	long long cost=0;

	scanf("%d", &N);

	for(int n=0;n<N;++n)
		parent[n]=n;

	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
		{
			scanf("%d", &C);

			if(i<j)
			{
				node edge={i, j, C};
				add(edge);
			}
		}

	while(connected<N-1)
	{
		node current=get();

		if(find_parent(current.src)!=find_parent(current.dst))
		{
			cost+=current.cost;
			union_parent(current.src,current.dst);
			++connected;
		}
	}

	printf("%lld", cost);
	return 0;
}