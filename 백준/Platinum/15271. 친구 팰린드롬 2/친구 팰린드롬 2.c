#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

int *partner=NULL, **friend=NULL, *friend_count=NULL;
bool *selected=NULL;

bool dfs(int current)
{
	for(int i=0;i<friend_count[current];++i)
		if(!selected[friend[current][i]])
		{
			selected[friend[current][i]]=true;

			if(partner[friend[current][i]]==0 || dfs(partner[friend[current][i]]))
			{
				partner[friend[current][i]]=current;
				return true;
			}
		}

	return false;
}

int main(void)
{
	int N, M, u, v, *like=NULL, count=0;

	scanf("%d%d", &N, &M);
	friend_count=(int *)calloc(N+1,sizeof(int));
	friend=(int **)malloc((N+1)*sizeof(int *));
	like=(int *)malloc(M*sizeof(int));

	for(int m=0;m<M;++m)
	{
		scanf("%d%d", &u, &v);

		if((u&1)==(v&1))
		{
			--m;
			--M;
			continue;
		}

		if(v&1)
		{
			int temp=u;
			u=v;
			v=temp;
		}

		++friend_count[u];
		like[m]=u<<8|v;
	}

	for(int n=1;n<=N;n+=2)
	{
		friend[n]=(int *)malloc(friend_count[n]*sizeof(int));
		friend_count[n]=0;
	}

	for(int m=0;m<M;++m)
	{
		u=like[m]>>8;
		friend[u][friend_count[u]++]=like[m]&255;
	}
	free(like);

	selected=(bool *)malloc((N+1)*sizeof(bool));
	partner=(int *)calloc(N+1,sizeof(int));
	for(int i=1;i<=N;i+=2)
	{
		for(int j=1;j<=N;++j)
			selected[j]=false;
		dfs(i);
	}

	for(int n=1;n<=N;++n)
	{
		count+=partner[n]>0;
		free(friend[n]);
	}
	count<<=1;
	count+=count<N;

	printf("%d", count);
	free(friend);
	free(friend_count);
	free(partner);
	free(selected);
	return 0;
}