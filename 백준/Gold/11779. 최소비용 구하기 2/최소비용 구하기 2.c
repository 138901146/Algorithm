#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int *city=NULL, *pq=NULL, size=1;

void add(int value)
{
	pq[size++]=value;
	int index=size-1;

	while(index>1)
		if(city[pq[index]]<=city[pq[index>>1]])
		{
			int temp=pq[index];
			pq[index]=pq[index>>1];
			pq[index>>1]=temp;
			index>>=1;
		}
		else
			break;
}

int get()
{
	bool set=false;
	int value=pq[1], index=1;
	pq[1]=pq[--size];

	while(index<size &&!set)
	{
		if((index<<1)+1<size)
		{
			if(city[pq[(index<<1)+1]]<city[pq[index<<1]])
			{
				if(city[pq[index]]>=city[pq[(index<<1)+1]])
				{
					int temp=pq[index];
					pq[index]=pq[(index<<1)+1];
					pq[(index<<1)+1]=temp;
					index=(index<<1)+1;
				}
				else
					set=true;
			}
			else
			{
				if(city[pq[index]]>=city[pq[index<<1]])
				{
					int temp=pq[index];
					pq[index]=pq[index<<1];
					pq[index<<1]=temp;
					index<<=1;
				}
				else
					set=true;
			}
		}
		else if((index<<1)+1==size)
		{
				if(city[pq[index]]>=city[pq[index<<1]])
				{
					int temp=pq[index];
					pq[index]=pq[index<<1];
					pq[index<<1]=temp;
					index<<=1;
				}
				else
					set=true;
		}
		else
			set=true;
	}

	return value;
}

int main(void)
{
	int n, m, **bus=NULL, *bus_count=NULL, ***local_bus=NULL, *previous=NULL, source, destination, *route=NULL, move=0, temp;

	scanf("%d", &n);
	scanf("%d", &m);
	city=(int *)malloc((n+1)*sizeof(int));
	previous=(int *)malloc((n+1)*sizeof(int));
	bus_count=(int *)calloc(n+1,sizeof(int));
	bus=(int **)malloc(m*sizeof(int *));
	local_bus=(int ***)malloc((n+1)*sizeof(int **));
	pq=(int *)malloc(1000*(n+1)*sizeof(int));
	for(int i=1;i<=n;i++)
		city[i]=1<<29;
	for(int i=0;i<m;i++)
	{
		bus[i]=(int *)malloc(3*sizeof(int));
		for(int j=0;j<3;j++)
			scanf("%d", &bus[i][j]);
		bus_count[bus[i][0]]++;
	}
	scanf("%d%d", &source, &destination);

	for(int i=1;i<=n;i++)
	{
		local_bus[i]=(int **)malloc(bus_count[i]*sizeof(int *));
		for(int j=0;j<bus_count[i];j++)
			local_bus[i][j]=(int *)malloc(2*sizeof(int));
		bus_count[i]=0;
		previous[i]=source;
	}

	for(int i=0;i<m;i++)
	{
		local_bus[bus[i][0]][bus_count[bus[i][0]]][0]=bus[i][1];
		local_bus[bus[i][0]][bus_count[bus[i][0]]++][1]=bus[i][2];
		free(bus[i]);
	}
	free(bus);

	city[source]=0;
	for(int i=0;i<bus_count[source];i++)
		if(local_bus[source][i][1]<city[local_bus[source][i][0]])
			city[local_bus[source][i][0]]=local_bus[source][i][1];

	for(int i=1;i<=n;i++)
		add(i);

	while(size>1)
	{
		int target=get();

		for(int i=0;i<bus_count[target];i++)
			if(city[local_bus[target][i][0]]>city[target]+local_bus[target][i][1])
			{
				city[local_bus[target][i][0]]=city[target]+local_bus[target][i][1];
				previous[local_bus[target][i][0]]=target;
				add(local_bus[target][i][0]);
			}
	}

	temp=destination;
	while(temp!=source)
	{
		temp=previous[temp];
		move++;
	}
	route=(int *)malloc((move+1)*sizeof(int));
	temp=destination;
	printf("%d\n%d\n%d ", city[destination], move+1, source);
	while(temp!=source)
	{
		route[--move]=temp;
		temp=previous[temp];
	}
	for(int i=0;route[i]!=destination;i++)
		printf("%d ", route[i]);
	printf("%d\n", destination);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<bus_count[i];j++)
			free(local_bus[i][j]);
		free(local_bus[i]);
	}
	free(local_bus);
	free(bus_count);
	free(city);
	free(previous);
	free(pq);
	free(route);
	return 0;
}