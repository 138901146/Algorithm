#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, M, **toy=NULL, ***primitive=NULL, *primitive_count=NULL, **relation=NULL, *definitive_count=NULL, **definitive=NULL, queue[100], front=0, rear=0, basic[100], basic_count=0;

	scanf("%d", &N);
	toy=(int **)malloc((N+1)*sizeof(int *));
	primitive=(int ***)malloc((N+1)*sizeof(int **));
	definitive=(int **)malloc((N+1)*sizeof(int *));
	primitive_count=(int *)calloc(N+1,sizeof(int));
	definitive_count=(int *)calloc(N+1,sizeof(int));

	scanf("%d", &M);
	relation=(int **)malloc(M*sizeof(int *));
	for(int m=0;m<M;m++)
	{
		relation[m]=(int *)malloc(3*sizeof(int));
		for(int i=0;i<3;i++)
			scanf("%d", &relation[m][i]);
		primitive_count[relation[m][0]]++;
		definitive_count[relation[m][1]]++;
	}

	for(int n=1;n<=N;n++)
	{
		toy[n]=(int *)calloc(N+1,sizeof(int));
		primitive[n]=(int **)malloc((primitive_count[n]+1)*sizeof(int *));
		definitive[n]=(int *)malloc(definitive_count[n]*sizeof(int));
		for(int i=0;i<=primitive_count[n];i++)
			primitive[n][i]=(int *)malloc(2*sizeof(int));
		primitive[n][0][0]=primitive_count[n];
		primitive_count[n]=definitive_count[n]=0;
	}

	for(int m=0;m<M;m++)
	{
		primitive[relation[m][0]][primitive_count[relation[m][0]]+1][0]=relation[m][1];
		primitive[relation[m][0]][++primitive_count[relation[m][0]]][1]=relation[m][2];
		definitive[relation[m][1]][definitive_count[relation[m][1]]++]=relation[m][0];
		free(relation[m]);
	}
	free(relation);

	for(int n=1;n<=N;n++)
		if(primitive_count[n]==0)
		{
			queue[rear++]=n;
			toy[n][n]=1;
			basic[basic_count++]=n;
		}


	while(front<rear)
	{
		for(int i=1;i<=primitive[queue[front]][0][0];i++)
			for(int j=0;j<basic_count;j++)
				toy[queue[front]][basic[j]]+=primitive[queue[front]][i][1]*toy[primitive[queue[front]][i][0]][basic[j]];

		for(int i=0;i<definitive_count[queue[front]];i++)
		{
			primitive_count[definitive[queue[front]][i]]--;
			if(primitive_count[definitive[queue[front]][i]]==0)
				queue[rear++]=definitive[queue[front]][i];
		}

		if(queue[front]==N)
			break;

		front++;
	}

	for(int i=0;i<basic_count;i++)
		if(toy[N][basic[i]]>0)
			printf("%d %d\n", basic[i], toy[N][basic[i]]);
	free(primitive_count);
	free(definitive_count);
	for(int n=1;n<=N;n++)
	{
		int num=primitive[n][0][0];
		for(int i=0;i<=num;i++)
			free(primitive[n][i]);
		free(primitive[n]);
		free(definitive[n]);
		free(toy[n]);
	}
	free(toy);
	return 0;
}