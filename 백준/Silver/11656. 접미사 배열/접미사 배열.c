#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int length;
	char S[1001]={'\0', }, **smaller=NULL;

	scanf("%s", S);
	length=strlen(S);
	smaller=(char **)malloc(length*sizeof(char *));
	for(int i=0;i<length;i++)
	{
		smaller[i]=(char *)calloc(length+1,sizeof(char));
		strcpy(smaller[i],S+i);
	}

	for(int i=0;i<length-1;i++)
		for(int j=i+1;j<length;j++)
			if(strcmp(smaller[i],smaller[j])>0)
			{
				char temp[1001]={'\0', };

				strcpy(temp,smaller[i]);
				strcpy(smaller[i],smaller[j]);
				strcpy(smaller[j],temp);
			}

	for(int i=0;i<length;i++)
	{
		printf("%s\n", smaller[i]);
		free(smaller[i]);
	}
	free(smaller);
	return 0;
}