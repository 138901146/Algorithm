#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int divide_team(int **S,bool *selected,int N,int current,int count)
{
	if(current==N)
		if(count*2==N)
		{
			int start=0, link=0;

			for(int n=0;n<N;n++)
				if(selected[n])
				{
					for(int i=n+1;i<N;i++)
						if(selected[i])
							start+=S[i][n]+S[n][i];
				}
				else
				{
					for(int i=n+1;i<N;i++)
						if(!selected[i])
							link+=S[i][n]+S[n][i];
				}

			return start-link>0?start-link:link-start;
		}
		else
			return 100000000;
	if(count*2<N)
	{
		int start, link;

		link=divide_team(S,selected,N,current+1,count);
		selected[current]=true;
		start=divide_team(S,selected,N,current+1,count+1);
		selected[current]=false;

		return link<start?link:start;
	}
	else if(count*2==N)
		return divide_team(S,selected,N,N,count);
	else
		return 100000000;
}
int main(void)
{
	int N, **S=NULL;
	bool *selected=NULL;

	scanf("%d", &N);
	S=(int **)malloc(N*sizeof(int *));
	for(int i=0;i<N;i++)
	{
		S[i]=(int *)malloc(N*sizeof(int));
		for(int j=0;j<N;j++)
			scanf("%d", &S[i][j]);
	}
	selected=(bool *)calloc(N,sizeof(bool));

	printf("%d\n", divide_team(S,selected,N,0,0));
	for(int i=0;i<N;i++)
		free(S[i]);
	free(S);
	free(selected);
	return 0;
}