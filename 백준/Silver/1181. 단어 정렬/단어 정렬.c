#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char temp[20000][51]={'\0', };

void merge(char **str,int start,int end,int mid,int N)
{
	int i=start, j=mid+1;

	for(int k=start;k<=end;k++)
		if(j>end)
			strcpy(temp[k],str[i++]);
		else if(i>mid)
			strcpy(temp[k],str[j++]);
		else if(strlen(str[i])<strlen(str[j]) || strlen(str[i])==strlen(str[j])&&strcmp(str[i],str[j])<0)
			strcpy(temp[k],str[i++]);
		else
			strcpy(temp[k],str[j++]);

	for(int k=start;k<=end;k++)
		strcpy(str[k],temp[k]);
}

void merge_sort(char **str,int start,int end,int N)
{
	if(start<end)
	{
		int mid=(start+end)/2;
		merge_sort(str,start,mid,N);
		merge_sort(str,mid+1,end,N);
		merge(str,start,end,mid,N);
	}
}

int main(void)
{
	int N;
	char **str=NULL;

	scanf("%d", &N);
	getchar();
	str=(char **)malloc(N*sizeof(char *));
	for(int n=0;n<N;n++)
		str[n]=(char *)calloc(51,sizeof(char));

	for(int n=0;n<N;n++)
		scanf("%s", str[n]);

	merge_sort(str,0,N-1,N);

	printf("%s\n", str[0]);
	for(int n=1;n<N;n++)
		if(strcmp(str[n],str[n-1])!=0)
			printf("%s\n", str[n]);
	for(int n=0;n<N;n++)
		free(str[n]);
	free(str);
	return 0;
}