#include<stdio.h>
#include<stdbool.h>
#include<memory.h>

int adjacent_list[51][50], adjacent_list_count[51], occupied[50], student_count[3]={0}, student[3][50], min=100;
bool visited[50], hate[50][50]={0};

bool dfs(int current)
{
	for(int i=0;i<adjacent_list_count[current];++i)
	{
		int next=adjacent_list[current][i];

		if(!visited[next])
		{
			visited[next]=true;

			if(!occupied[next] || dfs(occupied[next]))
			{
				occupied[next]=current;
				return true;
			}
		}
	}

	return false;
}

void match(int x,int y)
{
	int count=0;

	memset(adjacent_list_count,0,51*sizeof(int));
	memset(occupied,0,50*sizeof(int));
	for(int i=0;i<student_count[x];++i)
		for(int j=0;j<student_count[y];++j)
			if(hate[student[x][i]][student[y][j]])
				adjacent_list[i+1][adjacent_list_count[i+1]++]=j;

	for(int i=1;i<=student_count[x];++i)
	{
		memset(visited,0,50);
		count+=dfs(i);
	}

	min=count<min?count:min;
}

int main(void)
{
	int N, G;

	scanf("%d", &N);
	for(int i=0;i<N;++i)
	{
		scanf("%1d", &G);
		student[G-1][student_count[G-1]++]=i;
	}

	getchar();
	for(int i=0;i<N;++i)
	{
		char str[51]={0};

		scanf("%s", str);

		for(int j=0;j<=i;++j)
			hate[i][j]=hate[j][i]=str[j]=='Y';
	}

	for(int i=0;i<3;++i)
		for(int j=i+1;j<3;++j)
			match(i,j);

	printf("%d", N-min);
	return 0;
}