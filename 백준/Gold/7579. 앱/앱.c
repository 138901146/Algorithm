#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

int main(void)
{
	int N, M, *m=NULL, *c=NULL, *cost=NULL, cost_sum=0, answer;
	bool **deactivated=NULL;

	scanf("%d%d", &N, &M);
	m=(int *)malloc(N*sizeof(int));
	c=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;n++)
		scanf("%d", &m[n]);
	for(int n=0;n<N;n++)
	{
		scanf("%d", &c[n]);
		cost_sum+=c[n];
	}

	cost=(int *)calloc(cost_sum+1,sizeof(int));
	deactivated=(bool **)malloc((cost_sum+1)*sizeof(bool *));

	for(int i=0;i<N;i++)
		for(int j=i+1;j<N;j++)
			if(c[i]>c[j] || c[i]==c[j]&&m[i]<m[j])
			{
				int temp=c[i];
				c[i]=c[j];
				c[j]=temp;
				temp=m[i];
				m[i]=m[j];
				m[j]=temp;
			}

	for(int i=0;i<=cost_sum;i++)
	{
		deactivated[i]=(bool *)calloc(N,sizeof(bool));
		for(int j=0;j<N&&i>=c[j];j++)
			if(cost[i]<cost[i-c[j]]+m[j] && !deactivated[i-c[j]][j])
			{
				for(int k=0;k<N;k++)
					deactivated[i][k]=deactivated[i-c[j]][k];
				deactivated[i][j]=true;
				cost[i]=cost[i-c[j]]+m[j];
			}
		if(cost[i]>=M)
		{
			answer=i;
			break;
		}
	}

	printf("%d\n", answer);
	for(int i=c[0];i<=answer;i++)
		free(deactivated[i]);
	free(deactivated);
	free(cost);
	free(c);
	free(m);
	return 0;
}