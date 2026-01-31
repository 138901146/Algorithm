#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<memory.h>

int **schedule=NULL, *schedule_count=NULL, *occupied=NULL;
bool *visited=NULL;

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

bool dfs(int current)
{
	for(int i=0;i<schedule_count[current];++i)
	{
		int next=schedule[current][i];

		if(!visited[next])
		{
			visited[next]=true;

			if(occupied[next]==-1||dfs(occupied[next]))
			{
				occupied[next]=current;
				return true;
			}
		}
	}

	return false;
}

int main(void)
{
	int N;

	scanf("%d", &N);

	while(N)
	{
		int date=0, issac_schedule_count, *issac_schedule=NULL, temp=1;

		scanf("%d", &issac_schedule_count);

		issac_schedule=(int *)malloc(issac_schedule_count*sizeof(int));

		for(int i=0;i<issac_schedule_count;++i)
			scanf("%d", &issac_schedule[i]);

		qsort((void *)issac_schedule,(size_t)issac_schedule_count,sizeof(int),compare);

		for(int i=1;i<issac_schedule_count;++i)
			if(issac_schedule[i]!=issac_schedule[i-1])
				issac_schedule[temp++]=issac_schedule[i];
		issac_schedule_count=temp;

		schedule=(int **)malloc(N*sizeof(int *));
		schedule_count=(int *)malloc(N*sizeof(int));

		for(int i=0;i<N;++i)
		{
			scanf("%d", &schedule_count[i]);

			schedule[i]=(int *)malloc(schedule_count[i]*sizeof(int));

			for(int j=0;j<schedule_count[i];++j)
			{
				int left=0, right=issac_schedule_count-1, near=right;

				scanf("%d", &schedule[i][j]);

				while(left<=right)
				{
					int mid=left+right>>1;

					if(schedule[i][j]<=issac_schedule[mid])
					{
						right=mid-1;
						near=mid;
					}
					else
						left=mid+1;
				}

				if(issac_schedule[near]==schedule[i][j])
					schedule[i][j]=near;
				else
				{
					--schedule_count[i];
					--j;
				}

			}
		}

		free(issac_schedule);
		visited=(bool *)malloc(issac_schedule_count*sizeof(bool));
		occupied=(int *)malloc(issac_schedule_count*sizeof(int));

		for(int i=0;i<issac_schedule_count;++i)
			occupied[i]=-1;

		for(int i=0;i<N;++i)
		{
			memset(visited,false,issac_schedule_count);
			date+=dfs(i);
		}

		printf("%d\n", date);
		for(int i=0;i<N;++i)
			free(schedule[i]);
		free(schedule);
		free(schedule_count);
		free(visited);
		free(occupied);

		scanf("%d", &N);
	}

	return 0;
}