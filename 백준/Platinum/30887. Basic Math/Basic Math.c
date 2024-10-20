#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<memory.h>

typedef struct
{
	int a, b;
}
pair;

int compare(const void *x,const void *y)
{
	return *(long long *)x<*(long long *)y?-1:1;
}

int adjacent_list[2501][3], occupied[7500]={0};
bool visited[7500];

bool dfs(int current)
{
	for(int i=0;i<3;++i)
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

int main(void)
{
	int n, count=0;
	long long output[7500], answer[7500];
	pair numbers[2500];

	scanf("%d", &n);

	for(int i=0;i<n;++i)
	{
		scanf("%d%d", &numbers[i].a, &numbers[i].b);

		output[count++]=numbers[i].a+numbers[i].b;
		output[count++]=numbers[i].a-numbers[i].b;
		output[count++]=(long long)numbers[i].a*numbers[i].b;
	}
	qsort((void *)output,(size_t)count,sizeof(long long),compare);

	count=1;
	answer[0]=output[0];
	for(int i=1;i<n*3;++i)
		if(output[i]!=output[i-1])
			answer[count++]=output[i];

	for(int i=0;i<n;++i)
	{
		int left=0, right=count-1, mid, index=0;
		long long target=numbers[i].a+numbers[i].b;

		while(left<=right)
		{
			mid=left+right>>1;

			if(answer[mid]<=target)
			{
				index=mid;
				left=mid+1;
			}
			else
				right=mid-1;
		}
		adjacent_list[i+1][0]=index;

		left=index=0;
		right=count-1;
		target=numbers[i].a-numbers[i].b;

		while(left<=right)
		{
			mid=left+right>>1;

			if(answer[mid]<=target)
			{
				index=mid;
				left=mid+1;
			}
			else
				right=mid-1;
		}
		adjacent_list[i+1][1]=index;

		left=index=0;
		right=count-1;
		target=(long long)numbers[i].a*numbers[i].b;

		while(left<=right)
		{
			mid=left+right>>1;

			if(answer[mid]<=target)
			{
				index=mid;
				left=mid+1;
			}
			else
				right=mid-1;
		}
		adjacent_list[i+1][2]=index;
	}

	for(int i=1;i<=n;++i)
	{
		memset(visited,0,7500);
		if(!dfs(i))
		{
			printf("impossible");
			return 0;
		}
	}

	for(int i=0;i<7500;++i)
		if(occupied[i])
			output[occupied[i]-1]=answer[i];

	for(int i=0;i<n;++i)
	{
		printf("%d ", numbers[i].a);
		if(numbers[i].a+numbers[i].b==output[i])
			printf("+");
		else if(numbers[i].a-numbers[i].b==output[i])
			printf("-");
		else
			printf("*");
		printf(" %d = %lld\n", numbers[i].b, output[i]);
	}

	return 0;
}