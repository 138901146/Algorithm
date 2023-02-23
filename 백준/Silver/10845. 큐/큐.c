#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int state=0, *queue=NULL, N, alive=0;

	scanf("%d", &N);

	queue=(int *)malloc(N*sizeof(int));
	while(getchar()!='\n');

	for(int i=0;i<N;i++)
	{
		char statement[15]={'\0', };

		fgets(statement,sizeof(statement),stdin);

		if(strncmp(statement,"push",4)==0)
		{
			int num=0;
			for(int j=5;statement[j]!='\0';j++)
				statement[j-5]=statement[j];
			num=atoi(statement);
			queue[state++]=num;
		}
		else if(strncmp(statement,"pop",3)==0)
			printf("%d\n", state==alive?-1:queue[alive++]);
		else if(strncmp(statement,"size",3)==0)
			printf("%d\n", state-alive);
		else if(strncmp(statement,"empty",5)==0)
			printf("%d\n", state==alive);
		else if(strncmp(statement,"back",4)==0)
			printf("%d\n", state==alive?-1:queue[state-1]);
		else if(strncmp(statement,"front",5)==0)
			printf("%d\n", alive==state?-1:queue[alive]);
		else
			printf("error: %s", statement);
	}

	return 0;
}