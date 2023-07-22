#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void)
{
	int N, L, **map=NULL, count=0;

	scanf("%d%d", &N, &L);
	map=(int **)malloc(N*sizeof(int *));

	for(int i=0;i<N;i++)
	{
		bool able=true, *slope=calloc(N,sizeof(bool));

		map[i]=(int *)malloc(N*sizeof(int));
		for(int j=0;j<N;j++)
			scanf("%d", &map[i][j]);

		for(int j=1;j<N&&able;j++)
			if(map[i][j]!=map[i][j-1])
			{
				if(abs(map[i][j]-map[i][j-1])>1)
					able=false;
				else if(map[i][j]>map[i][j-1])
				{
					if(j<L)
					{
						able=false;
						break;
					}
					for(int l=1;l<=L;l++)
						if(slope[j-l])
						{
							able=false;
							break;
						}
						else
							slope[j-l]=true;
				}
				else
				{
					if(j+L>N)
					{
						able=false;
						break;
					}
					for(int l=0;l<L;l++)
						if(slope[j+l])
						{
							able=false;
							break;
						}
						else
							slope[j+l]=true;
				}
			}

			count+=able;
			free(slope);
		}

	for(int i=0;i<N;i++)
	{
		bool able=true, *slope=calloc(N,sizeof(bool));

		for(int j=1;j<N&&able;j++)
			if(map[j][i]!=map[j-1][i])
			{
				if(abs(map[j][i]-map[j-1][i])>1)
					able=false;
				else if(map[j][i]>map[j-1][i])
				{
					if(j<L)
					{
						able=false;
						break;
					}
					for(int l=1;l<=L;l++)
						if(slope[j-l])
						{
							able=false;
							break;
						}
						else
							slope[j-l]=true;
				}
				else
				{
					if(j+L>N)
					{
						able=false;
						break;
					}
					for(int l=0;l<L;l++)
						if(slope[j+l])
						{
							able=false;
							break;
						}
						else
							slope[j+l]=true;
				}
			}

			count+=able;
			free(slope);
		}

	printf("%d\n", count);
	for(int n=0;n<N;n++)
		free(map[n]);
	free(map);
	return 0;
}