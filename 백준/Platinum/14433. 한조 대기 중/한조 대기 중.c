#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

int *troll=NULL;
bool *selected=NULL;

bool dfs(int **pick,int *pick_count,int current)
{
	for(int i=0;i<pick_count[current];++i)
		if(!selected[pick[current][i]])
		{
			selected[pick[current][i]]=true;

			if(troll[pick[current][i]]==0 || dfs(pick,pick_count,troll[pick[current][i]]))
			{
				troll[pick[current][i]]=current;
				return true;
			}
		}

	return false;
}

int main(void)
{
	int N, M, K1, K2, *pick1_count=NULL, *pick2_count=NULL, **pick1=NULL, **pick2=NULL, *select=NULL, player, pick, count1=0, count2=0;

	scanf("%d%d%d%d", &N, &M, &K1, &K2);
	pick1_count=(int *)calloc(N+1,sizeof(int));
	pick1=(int **)malloc((N+1)*sizeof(int *));
	select=(int *)malloc(K1*sizeof(int));

	for(int i=0;i<K1;++i)
	{
		scanf("%d%d", &player, &pick);
		++pick1_count[player];
		select[i]=player<<9|pick;
	}

	for(int n=1;n<=N;++n)
	{
		pick1[n]=(int *)malloc(pick1_count[n]*sizeof(int));
		pick1_count[n]=0;
	}

	for(int i=0;i<K1;++i)
	{
		player=select[i]>>9;
		pick1[player][pick1_count[player]++]=select[i]&511;
	}
	free(select);

	pick2_count=(int *)calloc(N+1,sizeof(int));
	pick2=(int **)malloc((N+1)*sizeof(int *));
	select=(int *)malloc(K2*sizeof(int));

	for(int i=0;i<K2;++i)
	{
		scanf("%d%d", &player, &pick);
		++pick2_count[player];
		select[i]=player<<9|pick;
	}

	for(int n=1;n<=N;++n)
	{
		pick2[n]=(int *)malloc(pick2_count[n]*sizeof(int));
		pick2_count[n]=0;
	}

	for(int i=0;i<K2;++i)
	{
		player=select[i]>>9;
		pick2[player][pick2_count[player]++]=select[i]&511;
	}
	free(select);

	selected=(bool *)malloc((M+1)*sizeof(bool));
	troll=(int *)calloc(M+1,sizeof(int));
	for(int n=1;n<=N;++n)
	{
		for(int m=1;m<=M;++m)
			selected[m]=false;
		dfs(pick1,pick1_count,n);
	}

	for(int m=1;m<=M;++m)
	{
		count1+=troll[m]>0;
		troll[m]=0;
	}

	for(int n=1;n<=N;++n)
	{
		for(int m=1;m<=M;++m)
			selected[m]=false;
		dfs(pick2,pick2_count,n);
	}

	for(int m=1;m<=M;++m)
		count2+=troll[m]>0;

	printf("%s", count1<count2?"네 다음 힐딱이":"그만 알아보자");
	for(int n=1;n<=N;++n)
	{
		free(pick1[n]);
		free(pick2[n]);
	}
	free(pick1);
	free(pick2);
	free(pick1_count);
	free(pick2_count);
	free(troll);
	free(selected);
	return 0;
}