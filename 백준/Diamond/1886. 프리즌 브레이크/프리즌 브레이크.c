#include<stdio.h>
#include<stdbool.h>
#include<memory.h>

#define INF 999

int adjacent_list[100][4400], adjacent_list_count[4400], occupied[4400];
bool visited[4400];

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
	int N, M, escape_location[44], escape_count=0, prisoner_location[100], prisoner_count=0, id[12][12], distance[44][100], left=0, right=100, mid, answer=100, dr[4]={-1,0,0,1}, dc[4]={0,-1,1,0};
	char map[12][13]={0};

	memset(id,-1,144*sizeof(int));

	scanf("%d%d", &N, &M);
	for(int n=0;n<N;++n)
	{
		scanf("%s", map[n]);

		for(int m=0;m<M;++m)
			if(map[n][m]=='D')
			{
				escape_location[escape_count]=n<<4|m;
				id[n][m]=escape_count++;
			}
			else if(map[n][m]=='.')
			{
				prisoner_location[prisoner_count]=n<<4|m;
				id[n][m]=prisoner_count++;
			}
	}

	for(int i=0;i<escape_count;++i)
	{
		int queue[144], front=0, rear=1;
		bool distance_visited[12][12]={false};

		for(int j=0;j<prisoner_count;++j)
			distance[i][j]=INF;

		queue[0]=escape_location[i];
		distance_visited[escape_location[i]>>4][escape_location[i]&15]=true;

		while(front<rear)
		{
			int d=queue[front]>>8, r=(queue[front]>>4)&15, c=queue[front]&15;

			for(int j=0;j<4;++j)
			{
				int next_r=r+dr[j], next_c=c+dc[j];

				if(next_r<0 || N<=next_r || next_c<0 || M<=next_c || distance_visited[next_r][next_c] || map[next_r][next_c]!='.')
					continue;

				distance_visited[next_r][next_c]=true;
				distance[i][id[next_r][next_c]]=d+1;
				queue[rear++]=d+1<<8|next_r<<4|next_c;
			}

			++front;
		}
	}

	for(int i=0;i<prisoner_count;++i)
	{
		bool escapable=false;

		for(int j=0;j<escape_count;++j)
			if(distance[j][i]!=INF)
			{
				escapable=true;
				break;
			}

		if(!escapable)
		{
			printf("impossible");
			return 0;
		}
	}

	while(left<=right)
	{
		int mid=left+right>>1, matched=0;

		for(int i=0;i<prisoner_count;++i)
		{
			adjacent_list_count[i]=0;
			for(int j=0;j<escape_count;++j)
				for(int k=distance[j][i];k<=mid;++k)
					adjacent_list[i][adjacent_list_count[i]++]=100*j+k;
		}

		memset(occupied,-1,4400*sizeof(int));
		for(int i=0;i<prisoner_count;++i)
		{
			memset(visited,0,4400);
			if(dfs(i))
				++matched;
			else
				break;
		}

		if(matched==prisoner_count)
		{
			answer=mid;
			right=mid-1;
		}
		else
			left=mid+1;
	}

	printf("%d", answer);
	return 0;
}