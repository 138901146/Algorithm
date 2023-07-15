#include<stdio.h>
#include<malloc.h>

unsigned long long *pq=NULL;
int size=1;

unsigned long long get(void)
{
	if(size<=1)
		return 1;
	int index=1;

	pq[0]=pq[1];
	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pq[left]<pq[right]?left:right:right==size?left:index;

		if(next==index)
			break;
		else if(pq[index]>pq[next])
		{
			unsigned long long temp=pq[index];
			pq[index]=pq[next];
			pq[next]=temp;
			index=next;
		}
		else
			break;
	}

	return pq[0];
}

void add(unsigned long long value)
{
	int index=size;
	pq[size++]=value;

	while(index>1)
	{
		int next=index>>1;

		if(pq[index]<pq[next])
		{
			unsigned long long temp=pq[index];
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
	int T, N;
	unsigned long long C;

	scanf("%d", &T);
	for(int t=0;t<T;t++)
	{
		unsigned long long mul=1, A, B;

		scanf("%d", &N);
		if(N==1)
		{
			scanf("%llu", &C);
			printf("1\n");
			continue;
		}

		pq=(unsigned long long *)malloc((N+2)*sizeof(unsigned long long));

		size=1;
		for(int n=0;n<N;n++)
		{
			scanf("%llu", &C);
			add(C);
		}

		while(size>2)
		{
			A=get();
			B=get();

			add(A*B);
			mul*=(A*B)%1000000007;
			mul%=1000000007;
		}

		printf("%llu\n", mul);
		free(pq);
	}

	return 0;
}