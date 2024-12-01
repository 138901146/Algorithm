#include<stdio.h>
#include<stdbool.h>
#include<memory.h>

int adjacent_list[101][101], adjacent_list_count[101], occupied[101];
bool visited[101];

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
	int R, C, car_count=1, parking_lot_count=1, parking_lot[101], id[50][50]={0}, distance[101][101]={0}, queue[2500], dr[4]={1,0,0,-1}, dc[4]={0,1,-1,0}, left=0, right=3000, min=3000;
	char map[50][51]={0};

	scanf("%d%d", &R, &C);

	for(int r=0;r<R;++r)
		scanf("%s", map[r]);

	for(int r=0;r<R;++r)
		for(int c=0;c<C;++c)
			if(map[r][c]=='C')
				id[r][c]=car_count++;
			else if(map[r][c]=='P')
			{
				id[r][c]=parking_lot_count;
				parking_lot[parking_lot_count++]=r<<7|c;
			}

	if(car_count==1)
	{
		printf("0");
		return 0;
	}

	for(int r=0;r<R;++r)
		for(int c=0;c<C;++c)
			if(map[r][c]=='C')
			{
				bool local_visited[50][50]={false};
				int front=0, rear=1, local_distance[50][50]={0};

				local_visited[r][c]=true;
				queue[0]=r<<7|c;

				while(front<rear)
				{
					int front_r=queue[front]>>7, front_c=queue[front]&127;

					for(int i=0;i<4;++i)
					{
						int cur_r=front_r+dr[i], cur_c=front_c+dc[i];

						if(cur_r<0 || R<=cur_r || cur_c<0 || C<=cur_c || local_visited[cur_r][cur_c] || map[cur_r][cur_c]=='X')
							continue;

						local_distance[cur_r][cur_c]=local_distance[front_r][front_c]+1;
						local_visited[cur_r][cur_c]=true;
						queue[rear++]=cur_r<<7|cur_c;
					}

					++front;
				}

				for(int i=1;i<parking_lot_count;++i)
					distance[id[r][c]][i]=local_distance[parking_lot[i]>>7][parking_lot[i]&127];
			}

	while(left<=right)
	{
		int mid=left+right>>1, matched=0;

		memset(occupied,0,101*sizeof(int));

		for(int c=1;c<car_count;++c)
		{
			adjacent_list_count[c]=0;
			for(int p=1;p<parking_lot_count;++p)
				if(distance[c][p] && distance[c][p]<=mid)
					adjacent_list[c][adjacent_list_count[c]++]=p;
		}

		for(int c=1;c<car_count;++c)
		{
			memset(visited,0,101);

			if(dfs(c))
				++matched;
			else
				break;
		}

		if(matched+1==car_count)
		{
			min=mid;
			right=mid-1;
		}
		else
			left=mid+1;
	}

	printf("%d", min==3000?-1:min);
	return 0;
}