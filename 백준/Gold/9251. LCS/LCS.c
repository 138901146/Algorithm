#include<stdio.h>
#include<malloc.h>
#include<string.h>

int main(void)
{
	char str[2][1001]={'\0', };
	int **LCS=NULL, length[2];

	scanf("%s%s", str[0], str[1]);
	for(int i=0;i<2;i++)
		length[i]=strlen(str[i]);

	LCS=(int **)malloc((length[0]+1)*sizeof(int *));
	for(int i=0;i<=length[0];i++)
		LCS[i]=(int *)calloc(length[1]+1,sizeof(int));

	for(int i=1;i<=length[0];i++)
		for(int j=1;j<=length[1];j++)
			if(str[0][i-1]!=str[1][j-1])
				LCS[i][j]=LCS[i-1][j]>LCS[i][j-1]?LCS[i-1][j]:LCS[i][j-1];
			else
				LCS[i][j]=LCS[i-1][j-1]+1>=LCS[i-1][j]&&LCS[i-1][j-1]+1>=LCS[i][j-1]?LCS[i-1][j-1]+1:LCS[i-1][j]>=LCS[i-1][j-1]+1&&LCS[i-1][j]>=LCS[i][j-1]?LCS[i-1][j]:LCS[i][j-1];

	printf("%d\n", LCS[length[0]][length[1]]);
	for(int i=0;i<=length[0];i++)
		free(LCS[i]);
	free(LCS);
	return 0;
}