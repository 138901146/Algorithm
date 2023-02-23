#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void)
{
	int n, m, a, b, count=0;
	bool **list=NULL, *coming=NULL;

	scanf("%d", &n);
	list=(bool **)malloc(n*sizeof(bool *));
	for(int i=0;i<n;i++)
		list[i]=(bool *)calloc(n,sizeof(bool));
	coming=(bool *)calloc(n,sizeof(bool));

	scanf("%d", &m);

	for(int i=0;i<m;i++)
	{
		scanf("%d %d", &a, &b);
		a--;
		b--;

		list[a][b]=true;
		list[b][a]=true;
	}

	for(int i=1;i<n;i++)
		if(list[0][i])
		{
			coming[i]=true;
			for(int j=1;j<n;j++)
				if(list[i][j])
					coming[j]=true;
		}

	for(int i=1;i<n;i++)
		count+=coming[i];

	printf("%d\n", count);
	free(coming);
	for(int i=0;i<n;i++)
		free(list[i]);
	free(list);
	return 0;
}