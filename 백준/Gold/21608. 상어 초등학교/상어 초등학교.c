#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, seat[20][20]={0}, order[400], friend[401][4], dr[4]={-1,0,0,1}, dc[4]={0,-1,1,0}, sum=0;

	scanf("%d", &N);

	for(int i=0;i<N*N;++i)
	{
		scanf("%d", &order[i]);
		for(int j=0;j<4;++j)
			scanf("%d", &friend[order[i]][j]);
	}

	for(int i=0;i<N*N;++i)
	{
		int prefer_max=0, prefer_count=0, prefer[20][20]={0}, empty_max=0, empty_count=0, empty[20][20]={0};
		bool done=false;

		for(int r=0;r<N;++r)
			for(int c=0;c<N;++c)
			{
				if(seat[r][c])
					continue;

				for(int j=0;j<4;++j)
				{
					int next_r=r+dr[j], next_c=c+dc[j];

					if(next_r<0||N<=next_r||next_c<0||N<=next_c||!seat[next_r][next_c])
						continue;

					for(int k=0;k<4;++k)
						if(seat[next_r][next_c]==friend[order[i]][k])
						{
							++prefer[r][c];
							break;
						}
				}

				if(prefer_max<prefer[r][c])
				{
					prefer_max=prefer[r][c];
					prefer_count=1;
				}
				else if(prefer_max==prefer[r][c])
					++prefer_count;
			}

		if(prefer_count==1)
		{
			for(int r=0;r<N&&!done;++r)
				for(int c=0;c<N&&!done;++c)
					if(!seat[r][c]&&prefer[r][c]==prefer_max)
					{
						seat[r][c]=order[i];
						done=true;
					}

			continue;
		}

		for(int r=0;r<N;++r)
			for(int c=0;c<N;++c)
			{
				if(seat[r][c]||prefer[r][c]!=prefer_max)
					continue;

				for(int j=0;j<4;++j)
				{
					int next_r=r+dr[j], next_c=c+dc[j];

					if(next_r<0||N<=next_r||next_c<0||N<=next_c)
						continue;

					if(!seat[next_r][next_c])
						++empty[r][c];
				}

				if(empty_max<empty[r][c])
				{
					empty_max=empty[r][c];
					empty_count=1;
				}
				else if(empty_max==empty[r][c])
					++empty_count;
			}

		for(int r=0;r<N&&!done;++r)
			for(int c=0;c<N&&!done;++c)
				if(!seat[r][c]&&prefer[r][c]==prefer_max&&empty[r][c]==empty_max)
				{
					seat[r][c]=order[i];
					done=true;
				}
	}

	for(int r=0;r<N;++r)
		for(int c=0;c<N;++c)
		{
			int count=0;

			for(int i=0;i<4;++i)
			{
				int next_r=r+dr[i], next_c=c+dc[i];

				if(next_r<0||N<=next_r||next_c<0||N<=next_c)
					continue;

				for(int j=0;j<4;++j)
					if(friend[seat[r][c]][j]==seat[next_r][next_c])
					{
						++count;
						break;
					}
			}

			if(count)
			{
				int satisfy=1;

				while(--count)
					satisfy*=10;

				sum+=satisfy;
			}
		}

	printf("%d", sum);
	return 0;
}