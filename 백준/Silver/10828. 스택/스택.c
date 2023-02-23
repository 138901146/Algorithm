#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int state=0, *stack=NULL, N;

	scanf("%d", &N);
	stack=(int *)malloc(N*sizeof(int));
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
			stack[state++]=num;
		}
		else if(strncmp(statement,"pop",3)==0)
			printf("%d\n", state==0?-1:stack[--state]);
		else if(strncmp(statement,"size",4)==0)
			printf("%d\n", state);
		else if(strncmp(statement,"empty",5)==0)
			printf("%d\n", state==0);
		else if(strncmp(statement,"top",3)==0)
			printf("%d\n", state==0?-1:stack[state-1]);
		else
			printf("error: %s", statement);
	}

	return 0;
}