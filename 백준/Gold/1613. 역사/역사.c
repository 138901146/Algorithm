#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int n, k, s, x, y;
	char **relation=NULL;

	scanf("%d%d", &n, &k);
	relation=(char **)malloc((n+1)*sizeof(char *));
	for(int i=1;i<=n;++i)
		relation[i]=(char *)calloc(n+1,sizeof(char));

	while(k--)
	{
		scanf("%d%d", &x, &y);
		relation[x][y]=-1;
		relation[y][x]=1;
	}

	for(int mid=1;mid<=n;++mid)
		for(int start=1;start<=n;++start)
		{
			if(start==mid)
				continue;

			for(int end=1;end<=n;++end)
			{
				if(start==end||mid==end)
					continue;

				if(0<relation[start][mid]*relation[mid][end])
				{
					relation[start][end]=relation[start][mid];
					relation[end][start]=-relation[start][end];
				}
			}
		}

	scanf("%d", &s);
	while(s--)
	{
		scanf("%d%d", &x, &y);
		printf("%d\n", relation[x][y]);
	}

	while(n)
		free(relation[n--]);
	free(relation);
	return 0;
}