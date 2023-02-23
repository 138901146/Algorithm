#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int main(void)
{
	int N, K, *W=NULL, *V=NULL, *put=NULL, max=0;
	bool **used=NULL;

	scanf("%d%d", &N, &K);
	W=(int *)malloc(N*sizeof(int));
	V=(int *)malloc(N*sizeof(int));
	put=(int *)calloc(K+1,sizeof(int));
	used=(bool **)malloc((K+1)*sizeof(bool *));
	for(int k=0;k<=K;k++)
		used[k]=(bool *)calloc(N,sizeof(bool));

	for(int n=0;n<N;n++)
		scanf("%d%d", &W[n], &V[n]);

	for(int i=0;i<N;i++)
		for(int j=i+1;j<N;j++)
			if(W[i]>W[j] || W[i]==W[j]&&V[i]<V[j])
			{
				int temp=W[i];
				W[i]=W[j];
				W[j]=temp;
				temp=V[i];
				V[i]=V[j];
				V[j]=temp;
			}

	for(int i=W[0];i<=K;i++)
	{
		for(int j=0;j<N&&i-W[j]>=0;j++)
			if(put[i-W[j]]+V[j]>put[i] && !used[i-W[j]][j])
			{
				for(int k=0;k<N;k++)
					used[i][k]=used[i-W[j]][k];
				used[i][j]=true;
				put[i]=put[i-W[j]]+V[j];
			}
		max=put[i]>max?put[i]:max;
	}

	printf("%d\n", max);
	free(put);
	for(int k=0;k<=K;k++)
		free(used[k]);
	free(used);
	free(V);
	free(W);
	return 0;
}