#include<stdio.h>
#include<stdlib.h>

int *pq=NULL, size=1;

typedef struct
{
	int start, end;
}
meeting;

int compare(const void *x,const void *y)
{
	return (((meeting *)x)->end>((meeting *)y)->end || ((meeting *)x)->end==((meeting *)y)->end && ((meeting *)x)->start>((meeting *)y)->start)?-1:1;
}

void add(int data)
{
	int index=size;

	pq[size++]=data;

	while(index>1)
	{
		int next=index>>1;

		if(pq[index]>pq[next])
		{
			int temp=pq[index];
			pq[index]=pq[next];
			pq[next]=temp;
			index=next;
		}
		else
			break;
	}
}

int get()
{
	int index=1;
	pq[0]=pq[1];
	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pq[right]>pq[left]?right:left:right==size?left:index;

		if(next==index)
			break;
		else if(pq[next]>pq[index])
		{
			int temp=pq[index];
			pq[index]=pq[next];
			pq[next]=temp;
			index=next;
		}
		else
			break;
	}

	return pq[0];
}

int main(void)
{
	int N;
	meeting *session=NULL;

	scanf("%d", &N);
	session=(meeting *)malloc(N*sizeof(meeting));
	pq=(int *)malloc((N+1)*sizeof(int));

	for(int n=0;n<N;n++)
		scanf("%d%d", &session[n].start, &session[n].end);

	qsort((void *)session,(size_t)N,sizeof(meeting),compare);

	pq[size++]=session[0].start;
	for(int n=1;n<N;n++)
		if(session[n].end<=pq[1])
		{
			get();
			add(session[n].start);
		}
		else
			add(session[n].start);

	printf("%d", size-1);
	free(pq);
	free(session);
	return 0;
}