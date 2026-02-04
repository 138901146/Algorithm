#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int p, d;
}
class;

class *pq=NULL;
int size=1;

int compare(const void *x,const void *y)
{
	return ((class *)x)->d<((class *)y)->d?1:-1;
}

class get(void)
{
	int index=1;

	pq[0]=pq[1];
	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pq[left].p<pq[right].p?right:pq[right].p<pq[left].p?left:pq[left].d<pq[right].d?left:right:left<size?left:index;

		if(pq[next].p<pq[index].p||pq[index].p==pq[next].p&&pq[index].d<=pq[next].d)
			break;

		class temp=pq[index];
		pq[index]=pq[next];
		pq[next]=temp;
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

		if(pq[index].p<pq[next].p||pq[index].p==pq[next].p&&pq[next].d<=pq[index].d)
			break;

		pq[0]=pq[index];
		pq[index]=pq[next];
		pq[next]=pq[0];
		index=next;
	}
}

int main(void)
{
	int n, last=0, total=0;
	class *offer=NULL;

	scanf("%d", &n);

	if(!n)
	{
		printf("0");
		return 0;
	}

	offer=(class *)malloc(n*sizeof(class));
	pq=(class *)malloc((n+1)*sizeof(class));

	for(int i=0;i<n;++i)
		scanf("%d%d", &offer[i].p, &offer[i].d);

	qsort((void *)offer,(size_t)n,sizeof(class),compare);

	for(int i=offer[0].d;i;--i)
	{
		while(last<n&&i<=offer[last].d)
			add(offer[last++]);

		if(1<size)
			total+=get().p;
	}

	printf("%d", total);
	free(offer);
	free(pq);
	return 0;
}