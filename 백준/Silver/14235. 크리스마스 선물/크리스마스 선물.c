#include<stdio.h>
#include<malloc.h>

int size=1, pq[500001];

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

		pq[size]=pq[index];
		pq[index]=pq[next];
		pq[next]=pq[size];
		index=next;
	}

	return pq[0];
}

void add(int data)
{
	int index=size;

	pq[size++]=data;

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

int main(void)
{
	int n, a, present;

	scanf("%d", &n);

	while(n--)
	{
		scanf("%d", &a);

		if(a)
			while(a--)
			{
				scanf("%d", &present);
				add(present);
			}
		else
			printf("%d\n", size<2?-1:get());
	}

	return 0;
}