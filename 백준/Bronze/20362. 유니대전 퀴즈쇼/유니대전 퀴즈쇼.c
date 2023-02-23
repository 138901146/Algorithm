#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int N, count=0, correct;
	char ans[11]={'\0', }, S[11]={'\0', }, **chat=NULL, name[11]={'\0', };

	scanf("%d %s", &N, S);
	chat=(char **)malloc(N*sizeof(char *));
	for(int n=0;n<N;n++)
		chat[n]=(char *)calloc(11,sizeof(char));

	for(int n=0;n<N;n++)
	{
		scanf("%s %s", name, chat[n]);

		if(strcmp(S,name)==0)
		{
			correct=n;
			strcpy(ans,chat[n]);
			break;
		}
	}

	for(int n=0;n<correct;n++)
		count+=strcmp(ans,chat[n])==0;

	printf("%d\n", count);
	for(int n=0;n<N;n++)
		free(chat[n]);
	free(chat);
	return 0;
}