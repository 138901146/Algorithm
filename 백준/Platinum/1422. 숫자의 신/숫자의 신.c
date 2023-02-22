#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare(char *a,char *b)
{
	int len_a=strlen(a), len_b=strlen(b);
	char *a_first=NULL, *b_first=NULL;

	if(len_a<len_b)
	{
		for(int i=0;i<len_b;i++)
			if(a[i%len_a]<b[i])
				return 1;
			else if(a[i%len_a]>b[i])
				return -1;
	}
	else
	{
		for(int i=0;i<len_a;i++)
			if(a[i]<b[i%len_b])
				return 1;
			else if(a[i]>b[i%len_b])
				return -1;
	}

	a_first=(char *)calloc(len_a+len_b,sizeof(char));
	strcpy(a_first,a);
	strcat(a_first,b);
	b_first=(char *)calloc(len_a+len_b,sizeof(char));
	strcpy(b_first,b);
	strcat(b_first,a);

	for(int i=0;i<len_a+len_b;i++)
		if(a_first[i]<b_first[i])
		{
			free(a_first);
			free(b_first);
			return 1;
		}
		else if(a_first[i]>b_first[i])
		{
			free(a_first);
			free(b_first);
			return -1;
		}

	free(a_first);
	free(b_first);
	return 1;
}

int main(void)
{
	int N, K, num, max=0;
	char **list=NULL;

	scanf("%d%d", &K, &N);
	list=(char **)malloc(N*sizeof(char *));
	for(int n=0;n<N;n++)
		list[n]=(char *)calloc(11,sizeof(char));

	for(int k=0;k<K;k++)
	{
		scanf("%d", &num);
		max=num>max?num:max;
		sprintf(list[k],"%d", num);
	}
	for(int i=K;i<N;i++)
		sprintf(list[i],"%d", max);

	for(int i=0;i<N;i++)
		for(int j=i+1;j<N;j++)
			if(compare(list[i],list[j])>0)
			{
				char temp[11]={'\0', };
				strcpy(temp,list[i]);
				strcpy(list[i],list[j]);
				strcpy(list[j],temp);
			}

	for(int n=0;n<N;n++)
		printf("%s", list[n]);
	printf("\n");

	for(int n=0;n<N;n++)
		free(list[n]);
	free(list);
	return 0;
}