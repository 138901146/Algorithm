#include<stdio.h>
#include<stdlib.h>

int *pq=NULL, size=1;

void add(int *time,int value)
{
	int index=size, temp;
	pq[size++]=value;

	while(index>1)
		if(time[pq[index]]<time[pq[index>>1]])
		{
			temp=pq[index];
			pq[index]=pq[index>>1];
			pq[index>>1]=temp;
			index>>=1;
		}
		else
			break;
}

int get(int *time)
{
	int value=pq[1], index=1, temp;
	pq[1]=pq[--size];

	while(index<size)
	{
		if((index<<1)+1<size)
		{
			if(time[pq[index<<1]]<time[pq[(index<<1)+1]])
			{
				if(time[pq[index]]>=time[pq[index<<1]])
				{
					temp=pq[index];
					pq[index]=pq[index<<1];
					pq[index<<1]=temp;
					index<<=1;
				}
				else
					break;
			}
			else
			{
				if(time[pq[index]]>=time[pq[(index<<1)+1]])
				{
					temp=pq[index];
					pq[index]=pq[(index<<1)+1];
					pq[(index<<1)+1]=temp;
					index=(index<<1)+1;
				}
				else
					break;
			}
		}
		else if((index<<1)+1==size)
		{
			if(time[pq[index]]>=time[pq[index<<1]])
			{
				temp=pq[index];
				pq[index]=pq[index<<1];
				pq[index<<1]=temp;
			}
			break;
		}
		else
			break;
	}

	return value;
}

int main(void)
{
	int N, M, X, **T=NULL, ***going_road=NULL, *going_count=NULL, ***back_road=NULL, *back_count=NULL, max=0, *go=NULL, *back=NULL;

	scanf("%d%d%d", &N, &M, &X);
	going_count=(int *)calloc(N+1,sizeof(int));
	back_count=(int *)calloc(N+1,sizeof(int));
	going_road=(int ***)malloc((N+1)*sizeof(int **));
	back_road=(int ***)malloc((N+1)*sizeof(int **));
	T=(int **)malloc(M*sizeof(int *));
	go=(int *)malloc((N+1)*sizeof(int));
	back=(int *)malloc((N+1)*sizeof(int));
	pq=(int *)malloc((N*M+1)*sizeof(int));

	for(int m=0;m<M;m++)
	{
		T[m]=(int *)malloc(3*sizeof(int));
		for(int i=0;i<3;i++)
			scanf("%d", &T[m][i]);
		going_count[T[m][0]]++;
		back_count[T[m][1]]++;
	}

	for(int n=1;n<=N;n++)
	{
		going_road[n]=(int **)malloc(going_count[n]*sizeof(int *));
		back_road[n]=(int **)malloc(back_count[n]*sizeof(int *));
		for(int i=0;i<going_count[n];i++)
			going_road[n][i]=(int *)malloc(2*sizeof(int));
		for(int i=0;i<back_count[n];i++)
			back_road[n][i]=(int *)malloc(2*sizeof(int));
		going_count[n]=back_count[n]=0;
		go[n]=back[n]=1<<25;
	}

	for(int m=0;m<M;m++)
	{
		going_road[T[m][0]][going_count[T[m][0]]][0]=T[m][1];
		going_road[T[m][0]][going_count[T[m][0]]++][1]=T[m][2];
		back_road[T[m][1]][back_count[T[m][1]]][0]=T[m][0];
		back_road[T[m][1]][back_count[T[m][1]]++][1]=T[m][2];
		free(T[m]);
	}
	free(T);

	go[X]=back[X]=0;
	for(int i=0;i<going_count[X];i++)
		if(go[going_road[X][i][0]]>=going_road[X][i][1])
		{
			go[going_road[X][i][0]]=going_road[X][i][1];
			add(go,going_road[X][i][0]);
		}

	while(size>0)
	{
		int next=get(go);

		for(int i=0;i<going_count[next];i++)
			if(go[going_road[next][i][0]]>=go[next]+going_road[next][i][1])
			{
				go[going_road[next][i][0]]=go[next]+going_road[next][i][1];
				add(go,going_road[next][i][0]);
			}
	}

	size=1;
	for(int i=0;i<back_count[X];i++)
		if(back[back_road[X][i][0]]>=back_road[X][i][1])
		{
			back[back_road[X][i][0]]=back_road[X][i][1];
			add(back,back_road[X][i][0]);
		}

	while(size>0)
	{
		int next=get(back);

		for(int i=0;i<back_count[next];i++)
			if(back[back_road[next][i][0]]>=back[next]+back_road[next][i][1])
			{
				back[back_road[next][i][0]]=back[next]+back_road[next][i][1];
				add(back,back_road[next][i][0]);
			}
	}

	for(int n=1;n<=N;n++)
	{
		max=go[n]+back[n]>max?go[n]+back[n]:max;
		for(int i=0;i<going_count[n];i++)
			free(going_road[n][i]);
		for(int i=0;i<back_count[n];i++)
			free(back_road[n][i]);
		free(going_road[n]);
		free(back_road[n]);
	}
	free(going_road);
	free(going_count);
	free(back_road);
	free(back_count);
	free(pq);
	free(go);
	free(back);
	printf("%d\n", max);
	return 0;
}