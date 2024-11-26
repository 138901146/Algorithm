#include<stdio.h>
#include<stdbool.h>
#include<memory.h>

int adjacent_list[100][100], adjacent_list_count[100], occupied[100];
bool visited[100];

int abs(int x)
{
	return x<0?-x:x;
}

bool dfs(int current)
{
	for(int i=0;i<adjacent_list_count[current];++i)
	{
		int next=adjacent_list[current][i];

		if(!visited[next])
		{
			visited[next]=true;

			if(occupied[next]==-1 || dfs(occupied[next]))
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
	int N, K=400000000, left=0, right=400000000, mid, student[100][2], tutor[100][2], distance[100][100]={0}, matched;

	scanf("%d", &N);
	for(int n=0;n<N;++n)
		for(int i=0;i<2;++i)
			scanf("%d", &student[n][i]);
	for(int n=0;n<N;++n)
		for(int i=0;i<2;++i)
			scanf("%d", &tutor[n][i]);

	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			distance[i][j]=abs(student[i][0]-tutor[j][0])+abs(student[i][1]-tutor[j][1]);

	while(left<=right)
	{
		memset(adjacent_list_count,0,100*sizeof(int));
		memset(occupied,-1,100*sizeof(int));
		matched=0;

		mid=left+right>>1;

		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				if(distance[i][j]<=mid)
					adjacent_list[i][adjacent_list_count[i]++]=j;

		for(int n=0;n<N;++n)
		{
			memset(visited,0,100);

			if(dfs(n))
				++matched;
			else
				break;
		}

		if(matched==N)
		{
			K=mid;
			right=mid-1;
		}
		else
			left=mid+1;
	}

	printf("%d", K);
	return 0;
}