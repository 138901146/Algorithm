#include<stdio.h>
#include<stdlib.h>

int *pq=NULL, size=1;

int get(void)
{
	int index=1;

	pq[0]=pq[1];
	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?abs(pq[left])<abs(pq[right])||abs(pq[left])==abs(pq[right])&&pq[left]<pq[right]?left:right:right==size?left:index;

		if(next==index || abs(pq[index])<abs(pq[next]) || abs(pq[index])==abs(pq[next])&&pq[index]<pq[next])
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

		if(abs(pq[index])<abs(pq[next]) || abs(pq[index])==abs(pq[next])&&pq[index]<pq[next])
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

int main(void)
{
	int N, x;

	scanf("%d", &N);
	pq=(int *)malloc((N+1)*sizeof(int));

	for(int n=0;n<N;n++)
	{
		scanf("%d", &x);

		if(x)
			add(x);
		else
			printf("%d\n", size==1?0:get());
	}

	free(pq);
	return 0;
}