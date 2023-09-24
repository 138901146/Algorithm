#include<stdio.h>

int size[11], pq[11][1000001];

int get(int position)
{
	int index=1;
	pq[position][0]=pq[position][1];
	pq[position][1]=pq[position][--size[position]];

	while(index<size[position])
	{
		int left=index<<1, right=left|1, next=right<size[position]?pq[position][left]>pq[position][right]?left:right:right==size[position]?left:index;

		if(pq[position][index]>=pq[position][next])
			break;

		int temp=pq[position][index];
		pq[position][index]=pq[position][next];
		pq[position][next]=temp;
		index=next;
	}

	return pq[position][0];
}

void add(int position,int value)
{
	int index=size[position];
	pq[position][size[position]++]=value;

	while(index>1)
	{
		int next=index>>1;

		if(pq[position][index]<=pq[position][next])
			break;

		int temp=pq[position][index];
		pq[position][index]=pq[position][next];
		pq[position][next]=temp;
		index=next;
	}
}

int main(void)
{
	int N, K, P, W, selected[11], sum=0;

	for(int i=0;i<11;++i)
		size[i]=1;

	scanf("%d%d", &N, &K);

	while(N--)
	{
		scanf("%d%d", &P, &W);
		add(--P,W);
	}

	while(K--)
	{
		for(int i=0;i<11;++i)
			if(size[i]>1)
				selected[i]=get(i);
			else
				selected[i]=-1;

		for(int i=0;i<11;++i)
			if(selected[i])
				--selected[i];

		for(int i=0;i<11;++i)
			if(selected[i]>=0)
				add(i,selected[i]);
	}

	for(int i=0;i<11;++i)
		sum+=size[i]>1?pq[i][1]:0;

	printf("%d", sum);
	return 0;
}