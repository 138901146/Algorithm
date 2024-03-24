#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int A;
	long long end;
}
staff;

staff *pq=NULL;
int size=1;

staff get(void)
{
	int index=1;

	pq[0]=pq[1];
	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pq[left].end<pq[right].end?left:right:right==size?left:index;

		if(pq[index].end<=pq[next].end)
			break;

		staff temp=pq[index];
		pq[index]=pq[next];
		pq[next]=temp;
		index=next;
	}

	return pq[0];
}

void add(staff value)
{
	int index=size;

	pq[size++]=value;

	while(1<index)
	{
		int next=index>>1;

		if(pq[next].end<=pq[index].end)
			break;

		pq[0]=pq[index];
		pq[index]=pq[next];
		pq[next]=pq[0];
		index=next;
	}
}

int main(void)
{
	int N, M;
	staff manager;

	scanf("%d%d", &N, &M);
	pq=(staff *)malloc((N+1)*sizeof(staff));

	while(N--)
	{
		scanf("%d", &manager.A);
		manager.end=manager.A;
		add(manager);
	}

	while(M--)
	{
		manager=get();
		manager.end+=manager.A;
		add(manager);
	}

	printf("%lld", manager.end-manager.A);
	free(pq);
	return 0;
}