#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int N, grid[20][20], sum=0;
	bool excluded[20][20]={false};

	scanf("%d", &N);

	for(int A=0;A<N;++A)
		for(int B=0;B<N;++B)
			scanf("%d", &grid[A][B]);

	for(int mid=0;mid<N;++mid)
		for(int start=0;start<N;++start)
			for(int end=0;end<N;++end)
				if(start!=mid && start!=end && mid!=end)
				{
					if(grid[start][mid]+grid[mid][end]==grid[start][end])
						excluded[start][end]=true;
					else if(grid[start][mid]+grid[mid][end]<grid[start][end])
					{
						printf("-1");
						return 0;
					}
				}

	for(int A=0;A<N;++A)
		for(int B=0;B<A;++B)
			if(!excluded[A][B])
				sum+=grid[A][B];

	printf("%d", sum);
	return 0;
}