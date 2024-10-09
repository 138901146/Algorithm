#include<stdio.h>
#include<stdbool.h>
#include<memory.h>
#include<math.h>

int adjacent_list[201][200], adjacent_list_count[201]={0}, occupied[200]={0};
bool visited[200];

bool isPower(long long x)
{
	long long y=sqrt(x);

	return y*y==x;
}

long long gcd(long long x,long long y)
{
	long long temp;

	if(x<y)
	{
		temp=x;
		x=y;
		y=temp;
	}

	while(y)
	{
		temp=x%y;
		x=y;
		y=temp;
	}

	return x;
}

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

int main(void)
{
	int N, count=0, odd_count=0, even_count=0;
	long long stick, odd[200], even[200];

	scanf("%d", &N);

	while(N--)
	{
		scanf("%lld", &stick);

		if(stick&1)
			odd[odd_count++]=stick;
		else
			even[even_count++]=stick;
	}

	for(int i=0;i<odd_count;++i)
		for(int j=0;j<even_count;++j)
			if(gcd(odd[i],even[j])==1 && isPower(odd[i]*odd[i]+even[j]*even[j]))
				adjacent_list[i+1][adjacent_list_count[i+1]++]=j;

	for(int i=1;i<=odd_count;++i)
	{
		memset(visited,0,200);
		count+=dfs(i);
	}

	printf("%d", count);
	return 0;
}