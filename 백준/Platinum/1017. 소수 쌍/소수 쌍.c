#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool visited[25];
int selected[25], edge[25][25], edge_size[25]={0};

bool is_prime(int x)
{
	for(int i=3;i*i<=x;i+=2)
		if(x%i==0)
			return false;
	return true;
}

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

bool dfs(int current)
{
	for(int i=0;i<edge_size[current];++i)
	{
		int vertex=edge[current][i];

		if(!visited[vertex])
		{
			visited[vertex]=true;

			if(selected[vertex]==-1 || (selected[vertex]>0 && dfs(selected[vertex])))
			{
				selected[vertex]=current;
				return true;
			}
		}
	}

	return false;
}

int main(void)
{
	int N, number, original[50], pair[50], original_count=1, pair_count=0, answer_list[25], answer_size=0;

	scanf("%d", &N);

	scanf("%d", &number);
	original[0]=number;
	for(int n=1;n<N;++n)
	{
		scanf("%d", &number);

		if((number&1)==(original[0]&1))
			original[original_count++]=number;
		else
			pair[pair_count++]=number;
	}

	if(original_count!=pair_count)
	{
		printf("-1");
		return 0;
	}

	qsort((void *)pair,(size_t)pair_count,sizeof(int),compare);

	for(int i=0;i<original_count;++i)
		for(int j=0;j<pair_count;++j)
			if(is_prime(original[i]+pair[j]))
				edge[i][edge_size[i]++]=j;

	for(int base=0;base<edge_size[0];++base)
	{
		int count=0;

		for(int i=0;i<pair_count;++i)
			selected[i]=-1;
		selected[edge[0][base]]=0;
		for(int i=1;i<original_count;++i)
		{
			for(int j=0;j<pair_count;++j)
				visited[j]=false;
			visited[edge[0][base]]=true;

			dfs(i);
		}

		for(int i=0;i<pair_count;++i)
			count+=selected[i]>=0;

		if(count==original_count)
			answer_list[answer_size++]=pair[edge[0][base]];
	}

	if(answer_size==0)
		printf("-1");
	else
		for(int i=0;i<answer_size;++i)
			printf("%d ", answer_list[i]);
	return 0;
}