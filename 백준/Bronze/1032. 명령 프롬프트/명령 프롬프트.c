#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int N, *different=NULL;
	char **str=NULL;

	scanf("%d", &N);
	str=(char **)malloc(N*sizeof(char *));
	for(int i=0;i<N;i++)
		str[i]=(char *)calloc(51,sizeof(char));

	for(int i=0;i<N;i++)
		scanf("%s", str[i]);
	different=(int *)calloc(strlen(str[0]),sizeof(int));

	for(int i=0;i<N-1;i++)
		for(int j=i+1;j<N;j++)
			for(int k=0;k<strlen(str[0]);k++)
			{
				if(different[k])
					continue;
				if(str[i][k]!=str[j][k])
				{
					different[k]=1;
					str[0][k]='?';
				}
			}

	printf("%s\n", str[0]);

	for(int i=0;i<N;i++)
		free(str[i]);
	free(str);
	free(different);
	return 0;
}