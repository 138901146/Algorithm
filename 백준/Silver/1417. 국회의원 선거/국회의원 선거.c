#include<stdio.h>

int pq[50], pick[50], size=1;

int get(void)
{
	int index=1;
	pq[0]=pq[1];
	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pick[pq[left]]>pick[pq[right]]?left:right:right==size?left:index;

		if(pick[pq[index]]>=pick[pq[next]])
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

		if(pick[pq[index]]<=pick[pq[next]])
			break;

		int temp=pq[index];
		pq[index]=pq[next];
		pq[next]=temp;
		index=next;
	}
}

int main(void)
{
	int N, dasom, count=0;

	scanf("%d", &N);

	if(N==1)
	{
		printf("0");
		return 0;
	}

	scanf("%d", &dasom);
	for(int n=1;n<N;++n)
	{
		scanf("%d", &pick[n]);
		add(n);
	}

	while(pick[pq[1]]>=dasom)
	{
		int first=get();
		--pick[first];
		++dasom;
		++count;
		add(first);
	}

	printf("%d", count);
	return 0;
}