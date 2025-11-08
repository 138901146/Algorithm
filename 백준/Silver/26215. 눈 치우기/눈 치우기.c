#include<stdio.h>
#include<malloc.h>

int *pq=NULL, size=1;

void add(int node)
{
	int index=size;

	pq[size++]=node;

	while(1<index)
	{
		int next=index>>1;

		if(pq[index]<=pq[next])
			break;

		pq[0]=pq[index];
		pq[index]=pq[next];
		pq[next]=pq[0];
		index=next;
	}
}

int get(void)
{
	int index=1;

	pq[0]=pq[1];
	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pq[left]<pq[right]?right:left:left<size?left:index;

		if(pq[next]<=pq[index])
			break;

		int temp=pq[index];
		pq[index]=pq[next];
		pq[next]=temp;
		index=next;
	}

	return pq[0];
}

int main(void)
{
	int N, a, total=0;

	scanf("%d", &N);
	pq=(int *)malloc((N+1)*sizeof(int));

	while(N--)
	{
		scanf("%d", &a);
		add(a);
	}

	while(1<size)
		if(2<size)
		{
			int pri=get(), sec=get();

			++total;

			if(--pri)
				add(pri);
			if(--sec)
				add(sec);
		}
		else
		{
			total+=pq[1];
			break;
		}

	printf("%d", 1440<total?-1:total);
	free(pq);
	return 0;
}