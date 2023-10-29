#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int h, o;
}
location;

int compare(const void *x,const void *y)
{
	return ((location *)x)->o<((location *)y)->o || ((location *)x)->o==((location *)y)->o && ((location *)x)->h<((location *)y)->h ? -1 : 1;
}

int pq[100001], size=1;

int get()
{
	int index=1;
	pq[0]=pq[1];
	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pq[left]<pq[right]?left:right:right==size?left:index;

		if(pq[index]<=pq[next])
			break;

		int temp=pq[next];
		pq[next]=pq[index];
		pq[index]=temp;
		index=next;
	}

	return pq[0];
}

void add(int value)
{
	int index=size;
	pq[size++]=value;

	while(index>1)
	{
		int next=index>>1;

		if(pq[index]>=pq[next])
			break;

		int temp=pq[next];
		pq[next]=pq[index];
		pq[index]=temp;
		index=next;
	}
}

int main(void)
{
	int n, d, count=0;
	location work[100000];

	scanf("%d", &n);

	for(int i=0;i<n;++i)
	{
		scanf("%d%d", &work[i].h, &work[i].o);

		if(work[i].h>work[i].o)
		{
			int temp=work[i].h;
			work[i].h=work[i].o;
			work[i].o=temp;
		}
	}
	qsort((void *)work,(size_t)n,sizeof(location),compare);

	scanf("%d", &d);

	for(int i=0, left=0;i<n;++i)
	{
		add(work[i].h);

		while(size>1 && work[i].o-pq[1]>d)
			get();

		count=size-1>count?size-1:count;
	}

	printf("%d", count);
	return 0;
}