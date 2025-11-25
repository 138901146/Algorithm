#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int id, start, end, room;
}
class;

class *pq=NULL;
int size=1;

int compare_by_start(const void *x,const void *y)
{
	return ((class *)x)->start<((class *)y)->start?-1:((class *)y)->start<((class *)x)->start?1:((class *)x)->end<((class *)y)->end?-1:1;
}

int compare_by_id(const void *x,const void *y)
{
	return ((class *)x)->id<((class *)y)->id?-1:1;
}

class get(void)
{
	int index=1;
	class node=pq[1];

	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=left<size?pq[left].end<pq[right].end?left:right:right<size?left:index;

		if(pq[index].end<=pq[next].end)
			break;

		pq[0]=pq[index];
		pq[index]=pq[next];
		pq[next]=pq[0];
		index=next;
	}

	return pq[0];
}

void add(class node)
{
	int index=size;

	pq[size++]=node;

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
	int N, K=1;
	class *list=NULL;

	scanf("%d", &N);
	list=(class *)malloc(N*sizeof(class));
	pq=(class *)malloc((N+1)*sizeof(class));

	for(int n=0;n<N;++n)
		scanf("%d%d%d", &list[n].id, &list[n].start, &list[n].end);
	qsort((void *)list,(size_t)N,sizeof(class),compare_by_start);

	list[0].room=1;
	add(list[0]);

	for(int n=1;n<N;++n)
	{
		if(pq[1].end<=list[n].start)
		{
			list[n].room=pq[1].room;
			get();
		}
		else
			list[n].room=++K;

		add(list[n]);
	}

	qsort((void *)list,(size_t)N,sizeof(class),compare_by_id);
	printf("%d", K);
	for(int n=0;n<N;++n)
		printf("\n%d", list[n].room);
	free(list);
	free(pq);
	return 0;
}