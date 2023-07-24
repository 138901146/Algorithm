#include<stdio.h>
#include<malloc.h>
#include<string.h>

int main(void)
{
	char str[2][1001]={'\0', };
	int **LCS=NULL, length[2], **prev=NULL, backtrack[1001];

	scanf("%s%s", str[0], str[1]);
	for(int i=0;i<2;i++)
		length[i]=strlen(str[i]);

	LCS=(int **)malloc((length[0]+1)*sizeof(int *));
	prev=(int **)malloc((length[0]+1)*sizeof(int *));
	for(int i=0;i<=length[0];i++)
	{
		LCS[i]=(int *)calloc(length[1]+1,sizeof(int));
		prev[i]=(int *)calloc(length[1]+1,sizeof(int));
		backtrack[i]=-1;
	}

	for(int i=1;i<=length[0];i++)
		for(int j=1;j<=length[1];j++)
			if(str[0][i-1]!=str[1][j-1])
				if(LCS[i-1][j]>LCS[i][j-1])
				{
					LCS[i][j]=LCS[i-1][j];
					prev[i][j]=prev[i-1][j];
				}
				else
				{
					LCS[i][j]=LCS[i][j-1];
					prev[i][j]=prev[i][j-1];
				}
			else
				if(LCS[i-1][j-1]+1>=LCS[i-1][j] && LCS[i-1][j-1]+1>=LCS[i][j-1])
				{
					LCS[i][j]=LCS[i-1][j-1]+1;
					prev[i][j]=(i-1)<<10|(j-1);
				}
				else if(LCS[i-1][j]>=LCS[i-1][j-1]+1 && LCS[i-1][j]>=LCS[i][j-1])
				{
					LCS[i][j]=LCS[i-1][j];
					prev[i][j]=prev[i-1][j];
				}
				else
				{
					LCS[i][j]=LCS[i][j-1];
					prev[i][j]=prev[i][j-1];
				}

	printf("%d\n", LCS[length[0]][length[1]]);
	if(LCS[length[0]][length[1]])
	{
		int x=length[0], y=length[1], current=LCS[x][y];

		while(current)
		{
			backtrack[current]=prev[x][y]>>10;
			y=prev[x][y]&1023;
			x=backtrack[current--];
		}

		for(int i=1;i<=LCS[length[0]][length[1]];i++)
			printf("%c", str[0][backtrack[i]]);
		printf("\n");
	}

	for(int i=0;i<=length[0];i++)
	{
		free(LCS[i]);
		free(prev[i]);
	}
	free(LCS);
	free(prev);
	return 0;
}