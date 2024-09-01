#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int deadline, reward;
}
question;

int compare(const void *x,const void *y)
{
	return ((question *)x)->deadline<((question *)y)->deadline?1:-1;
}

question *pq=NULL;
int size=1;

void add(question value)
{
	int index=size;

	pq[size++]=value;

	while(1<index)
	{
		int next=index>>1;

		if(pq[index].reward<=pq[next].reward)
			break;

		pq[0]=pq[index];
		pq[index]=pq[next];
		pq[next]=pq[0];
		index=next;
	}
}

question get(void)
{
	int index=1;

	pq[0]=pq[1];
	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pq[left].reward<pq[right].reward?right:left:right==size?left:index;

		if(pq[next].reward<=pq[index].reward)
			break;

		question temp=pq[index];
		pq[index]=pq[next];
		pq[next]=temp;
		index=next;
	}

	return pq[0];
}

int main(void)
{
	int N, enqueued=0, cupramen=0;
	question *list=NULL;

	scanf("%d", &N);
	list=(question *)malloc(N*sizeof(question));
	pq=(question *)malloc((N+1)*sizeof(question));

	for(int i=0;i<N;++i)
		scanf("%d%d", &list[i].deadline, &list[i].reward);
	qsort((void *)list,(size_t)N,sizeof(question),compare);

	for(int i=N;i;--i)
	{
		while(enqueued<N && i<=list[enqueued].deadline)
			add(list[enqueued++]);

		if(1<size)
			cupramen+=get().reward;
	}

	printf("%d", cupramen);
	free(list);
	free(pq);
	return 0;
}