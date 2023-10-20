#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int id, second;
}
infection;

infection pq[100000];
int size;

infection get(void)
{
	int index=1;

	pq[0]=pq[1];
	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pq[left].second<pq[right].second?left:right:right==size?left:index;

		if(pq[index].second<=pq[next].second)
			break;

		infection temp=pq[index];
		pq[index]=pq[next];
		pq[next]=temp;
		index=next;
	}

	return pq[0];
}

void add(infection computer)
{
	int index=size;

	pq[size++]=computer;

	while(index>1)
	{
		int next=index>>1;

		if(pq[index].second>=pq[next].second)
			break;

		infection temp=pq[index];
		pq[index]=pq[next];
		pq[next]=temp;
		index=next;
	}
}

int main(void)
{
	int T;

	scanf("%d", &T);

	while(T--)
	{
		int n, d, c, *hacked=NULL, **dependencies=NULL, *computer_count=NULL, max=0, count=0;
		infection **computer=NULL;

		scanf("%d%d%d", &n, &d, &c);
		computer_count=(int *)calloc(n+1,sizeof(int));
		computer=(infection **)malloc((n+1)*sizeof(infection *));
		dependencies=(int **)malloc(d*sizeof(int *));

		for(int i=0;i<d;++i)
		{
			dependencies[i]=(int *)malloc(3*sizeof(int));
			for(int j=0;j<3;++j)
				scanf("%d", &dependencies[i][j]);
			++computer_count[dependencies[i][1]];
		}

		for(int i=1;i<=n;++i)
		{
			computer[i]=(infection *)malloc(computer_count[i]*sizeof(infection));
			computer_count[i]=0;
		}

		for(int i=0;i<d;++i)
		{
			computer[dependencies[i][1]][computer_count[dependencies[i][1]]].id=dependencies[i][0];
			computer[dependencies[i][1]][computer_count[dependencies[i][1]]++].second=dependencies[i][2];
			free(dependencies[i]);
		}
		free(dependencies);

		hacked=(int *)malloc((n+1)*sizeof(int));
		for(int i=1;i<=n;++i)
			hacked[i]=2000000000;
		hacked[c]=0;

		size=1;
		for(int i=0;i<computer_count[c];++i)
		{
			hacked[computer[c][i].id]=computer[c][i].second;
			add(computer[c][i]);
		}

		while(size>1)
		{
			infection next=get();

			if(next.second==hacked[next.id])
				for(int i=0;i<computer_count[next.id];++i)
					if(hacked[computer[next.id][i].id]>next.second+computer[next.id][i].second)
					{
						infection temp;
						temp.second=hacked[computer[next.id][i].id]=next.second+computer[next.id][i].second;
						temp.id=computer[next.id][i].id;
						add(temp);
					}
		}

		for(int i=1;i<=n;++i)
		{
			if(hacked[i]<2000000000)
			{
				++count;
				max=hacked[i]>max?hacked[i]:max;
			}
			free(computer[i]);
		}

		printf("%d %d\n", count, max);
		free(computer);
		free(computer_count);
		free(hacked);
	}

	return 0;
}