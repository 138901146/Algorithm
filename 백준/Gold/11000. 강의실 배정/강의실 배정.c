#include<stdio.h>
#include<stdlib.h>

int *pq=NULL, size=1;

typedef struct
{
	int S, T;
}
class;

int compare(const void *x,const void *y)
{
	return (((class *)x)->T>((class *)y)->T || ((class *)x)->T==((class *)y)->T && ((class *)x)->S>((class *)y)->S)?-1:1;
}

void add(int data)
{
	int index=size;

	pq[size++]=data;

	while(index>1)
	{
		int next=index>>1;

		if(pq[index]<=pq[next])
			break;

		int temp=pq[index];
		pq[index]=pq[next];
		pq[next]=temp;
		index=next;
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
	int N;
	class *session=NULL;

	scanf("%d", &N);
	session=(class *)malloc(N*sizeof(class));
	pq=(int *)malloc((N+1)*sizeof(int));

	for(int n=0;n<N;n++)
		scanf("%d%d", &session[n].S, &session[n].T);

	qsort((void *)session,(size_t)N,sizeof(class),compare);

	pq[size++]=session[0].S;
	for(int n=1;n<N;n++)
		if(session[n].T<=pq[1])
		{
			get();
			add(session[n].S);
		}
		else
			add(session[n].S);

	printf("%d\n", size-1);
	free(pq);
	free(session);
	return 0;
}