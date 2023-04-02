#include<stdio.h>
#include<stdlib.h>

int genre_count[10]={0, }, price_sum[10][2001]={0, }, K, **remember_state=NULL;

int find_max(int index,int used)
{
	if(used==K)
		return 0;
	else if(index==9)
		return genre_count[9]<K-used?-200000000:price_sum[9][K-used];

	int search, max=0;

	for(int i=0;used+i<=K;i++)
		if(i<=genre_count[index])
		{
			if(remember_state[index+1][used+i]==-1)
				remember_state[index+1][used+i]=find_max(index+1,used+i);
			max=price_sum[index][i]+remember_state[index+1][used+i]<max?max:price_sum[index][i]+remember_state[index+1][used+i];
		}
		else
			break;

	remember_state[index][used]=max;
	return max;
}

int main(void)
{
	int N, *C=NULL, *G=NULL, temp;

	scanf("%d%d", &N, &K);
	C=(int *)malloc(N*sizeof(int));
	G=(int *)malloc(N*sizeof(int));
	remember_state=(int **)malloc(10*sizeof(int *));

	for(int i=0;i<N;i++)
	{
		scanf("%d%d", &C[i], &G[i]);
		price_sum[G[i]-1][++genre_count[G[i]-1]]=C[i];
	}

	for(int n=0;n<10;n++)
	{
		for(int i=1;i<=genre_count[n];i++)
			for(int j=i+1;j<=genre_count[n];j++)
				if(price_sum[n][i]<price_sum[n][j])
				{
					temp=price_sum[n][i];
					price_sum[n][i]=price_sum[n][j];
					price_sum[n][j]=temp;
				}

		for(int i=2;i<=genre_count[n];i++)
			price_sum[n][i]+=price_sum[n][i-1]+2*(i-1);
		remember_state[n]=(int *)malloc((K+1)*sizeof(int));
		for(int i=0;i<=K;i++)
			remember_state[n][i]=-1;
	}
	remember_state[9][K-1]=price_sum[9][1];

	printf("%d\n", find_max(0,0));
	for(int n=0;n<10;n++)
		free(remember_state[n]);
	free(remember_state);
	free(G);
	free(C);
	return 0;
}