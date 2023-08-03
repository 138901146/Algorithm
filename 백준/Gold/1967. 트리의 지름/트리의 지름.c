#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int index, value;
}
node;

int size=1;
node *pq=NULL;

node get(void)
{
	int current=1;

	pq[0]=pq[1];
	pq[1]=pq[--size];

	while(current<size)
	{
		int left=current<<1, right=left|1, next=right<size?pq[left].value<pq[right].value?left:right:size==right?left:current;

		if(pq[next].value>=pq[current].value)
			break;

		node temp=pq[current];
		pq[current]=pq[next];
		pq[next]=temp;
		current=next;
	}

	return pq[0];
}

void add(node n)
{
	int current=size;

	pq[size++]=n;

	while(current>1)
	{
		int next=current>>1;

		if(pq[current].value>=pq[next].value)
			break;

		node temp=pq[current];
		pq[current]=pq[next];
		pq[next]=temp;
		current=next;
	}
}

int main(void)
{
	int n, *edge_count=NULL, **edge=NULL, parent, *distance=NULL, max=0;
	node **child=NULL, temp;

	scanf("%d", &n);
	edge=(int **)malloc((n-1)*sizeof(int *));
	edge_count=(int *)calloc(n+1,sizeof(int));
	child=(node **)malloc((n+1)*sizeof(node *));

	for(int i=0;i<n-1;i++)
	{
		edge[i]=(int *)malloc(3*sizeof(int));
		for(int j=0;j<3;j++)
			scanf("%d", &edge[i][j]);
		
		edge_count[edge[i][0]]++;
		edge_count[edge[i][1]]++;
	}

	for(int i=1;i<=n;i++)
	{
		child[i]=(node *)malloc(edge_count[i]*sizeof(node));
		edge_count[i]=0;
	}

	for(int i=0;i<n-1;i++)
	{
		child[edge[i][0]][edge_count[edge[i][0]]].index=edge[i][1];
		child[edge[i][0]][edge_count[edge[i][0]]++].value=edge[i][2];
		child[edge[i][1]][edge_count[edge[i][1]]].index=edge[i][0];
		child[edge[i][1]][edge_count[edge[i][1]]++].value=edge[i][2];
		free(edge[i]);
	}
	free(edge);

	distance=(int *)malloc((n+1)*sizeof(int));
	for(int i=2;i<=n;i++)
		distance[i]=100000000;
	pq=(node *)malloc((n<<2)*sizeof(node));
	temp.index=1;
	distance[1]=temp.value=0;

	pq[size++]=temp;

	while(size>1)
	{
		node next=get();

		if(next.value>distance[next.index])
			continue;

		for(int i=0;i<edge_count[next.index];i++)
			if(distance[child[next.index][i].index]>next.value+child[next.index][i].value)
			{
				temp.value=distance[child[next.index][i].index]=next.value+child[next.index][i].value;
				temp.index=child[next.index][i].index;
				add(temp);
			}
	}

	temp.index=1;
	for(int i=2;i<=n;i++)
		temp.index=distance[i]>distance[temp.index]?i:temp.index;
	for(int i=1;i<=n;i++)
		distance[i]=100000000;
	distance[temp.index]=temp.value=0;

	pq[size++]=temp;

	while(size>1)
	{
		node next=get();

		if(next.value>distance[next.index])
			continue;

		for(int i=0;i<edge_count[next.index];i++)
			if(distance[child[next.index][i].index]>distance[next.index]+child[next.index][i].value)
			{
				temp.value=distance[child[next.index][i].index]=distance[next.index]+child[next.index][i].value;
				temp.index=child[next.index][i].index;
				add(temp);
			}
	}

	for(int i=1;i<=n;i++)
	{
		max=distance[i]>max?distance[i]:max;
		free(child[i]);
	}
	free(child);
	free(distance);
	free(edge_count);
	free(pq);
	printf("%d\n", max);
	return 0;
}