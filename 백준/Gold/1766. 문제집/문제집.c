#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int *pq=NULL, size=1;

void add(int value)
{
	pq[size++]=value;
	int index=size-1;

	while(index>1)
		if(pq[index]<=pq[index>>1])
		{
			int temp=pq[index];
			pq[index]=pq[index>>1];
			pq[index>>1]=temp;
			index>>=1;
		}
		else
			break;
}

int get()
{
	bool set=false;
	int value=pq[1], index=1;
	pq[1]=pq[--size];

	while(index<size &&!set)
	{
		if(index*2+1<size)
		{
			if(pq[index*2+1]<pq[index*2])
			{
				if(pq[index]>=pq[index*2+1])
				{
					int temp=pq[index];
					pq[index]=pq[index*2+1];
					pq[index*2+1]=temp;
					index=(index<<1)+1;
				}
				else
					set=true;
			}
			else
			{
				if(pq[index]>=pq[index*2])
				{
					int temp=pq[index];
					pq[index]=pq[index*2];
					pq[index*2]=temp;
					index<<=1;
				}
				else
					set=true;
			}
		}
		else if(index*2+1==size)
		{
				if(pq[index]>=pq[index*2])
				{
					int temp=pq[index];
					pq[index]=pq[index*2];
					pq[index*2]=temp;
					index<<=1;
				}
				else
					set=true;
		}
		else
			set=true;
	}

	return value;
}

int main(void)
{
	int N, M, **pri_order=NULL, **def_order=NULL, *pri_count=NULL, *def_count=NULL, *primitive=NULL, *definitive=NULL, *order=NULL, count=0;
	bool *visited=NULL;

	scanf("%d%d", &N, &M);
	pq=(int *)malloc((N+1)*sizeof(int));
	primitive=(int *)malloc(M*sizeof(int));
	definitive=(int *)malloc(M*sizeof(int));
	pri_order=(int **)malloc((N+1)*sizeof(int *));
	def_order=(int **)malloc((N+1)*sizeof(int *));
	pri_count=(int *)calloc(N+1,sizeof(int));
	def_count=(int *)calloc(N+1,sizeof(int));
	order=(int *)malloc(N*sizeof(int));
	visited=(bool *)calloc(N+1,sizeof(bool));

	for(int m=0;m<M;m++)
	{
		scanf("%d%d", &primitive[m], &definitive[m]);
		pri_count[primitive[m]]++;
		def_count[definitive[m]]++;
	}

	for(int n=1;n<=N;n++)
	{
		pri_order[n]=(int *)malloc((pri_count[n]+1)*sizeof(int));
		def_order[n]=(int *)malloc((def_count[n]+1)*sizeof(int));
		pri_order[n][0]=def_order[n][0]=0;
	}

	for(int m=0;m<M;m++)
	{
		pri_order[primitive[m]][++pri_order[primitive[m]][0]]=definitive[m];
		def_order[definitive[m]][++def_order[definitive[m]][0]]=primitive[m];
	}

	for(int n=1;n<=N;n++)
		if(def_count[n]==0)
		{
			visited[n]=true;
			add(n);
		}

	while(count<N)
	{
		int problem=order[count++]=get();

		for(int i=1;i<=pri_count[problem];i++)
		{
			def_count[pri_order[problem][i]]--;
			if(def_count[pri_order[problem][i]]==0 && !visited[pri_order[problem][i]])
			{
				visited[pri_order[problem][i]]=true;
				add(pri_order[problem][i]);
			}
		}
	}

	for(int i=0;i<count;i++)
		printf("%d ", order[i]);
	for(int n=1;n<=N;n++)
	{
		free(pri_order[n]);
		free(def_order[n]);
	}
	free(pri_order);
	free(def_order);
	free(pri_count);
	free(def_count);
	free(primitive);
	free(definitive);
	free(pq);
	free(visited);
	free(order);
	return 0;
}