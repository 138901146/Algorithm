#include<stdio.h>
#include<malloc.h>

int *pq=NULL, size=1;

int get()
{
	int index=1;
	pq[0]=pq[1];
	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pq[left]<pq[right]?left:right:size==right?left:index;

		if(pq[index]<=pq[next])
			break;

		int temp=pq[index];
		pq[index]=pq[next];
		pq[next]=temp;
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

		int temp=pq[index];
		pq[index]=pq[next];
		pq[next]=temp;
		index=next;
	}
}

int abs(int x)
{
	return x<0?-x:x;
}

int main(void)
{
	int N, A, init_max=0, min=2000000000, max;

	scanf("%d", &N);
	pq=(int *)malloc((N+1)*sizeof(int));

	while(N--)
	{
		scanf("%d", &A);
		init_max=A>init_max?A:init_max;
		add(A);
	}

	A=get();
	max=init_max;
	while(A<init_max)
	{
		min=abs(A-max)<min?abs(A-max):min;
		add(A<<1);
		max=(A<<1)>max?(A<<1):max;
		A=get();
	}
	min=abs(A-max)<min?abs(A-max):min;

	printf("%d", min);
	free(pq);
	return 0;
}