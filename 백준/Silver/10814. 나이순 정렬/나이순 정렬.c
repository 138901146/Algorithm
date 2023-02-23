#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int age_temp[100000];
char name_temp[100000][101]={'\0', };

void merge(int *age,char **name,int start,int end,int mid,int N)
{
	int i=start, j=mid+1;

	for(int k=	start;k<=end;k++)
		if(j>end)
		{
			age_temp[k]=age[i];
			strcpy(name_temp[k],name[i]);
			i++;
		}
		else if(i>mid)
		{
			age_temp[k]=age[j];
			strcpy(name_temp[k],name[j]);
			j++;
		}
		else if(age[i]>age[j])
		{
			age_temp[k]=age[j];
			strcpy(name_temp[k],name[j]);
			j++;
		}
		else
		{
			age_temp[k]=age[i];
			strcpy(name_temp[k],name[i]);
			i++;
		}

	for(int k=start;k<=end;k++)
	{
		age[k]=age_temp[k];
		strcpy(name[k],name_temp[k]);
	}
}

void mergesort(int *age,char **name,int start,int end,int N)
{
	if(start<end)
	{
		int mid=(start+end)/2;
		mergesort(age,name,start,mid,N);
		mergesort(age,name,mid+1,end,N);
		merge(age,name,start,end,mid,N);
	}
}

int main(void)
{
	int N, *age=NULL;
	char **name=NULL;

	scanf("%d", &N);
	age=(int *)malloc(N*sizeof(int));
	name=(char **)malloc(N*sizeof(char *));
	for(int n=0;n<N;n++)
		name[n]=(char *)calloc(101,sizeof(char));

	for(int n=0;n<N;n++)
		scanf("%d %s", &age[n], name[n]);

	mergesort(age,name,0,N-1,N);

	for(int n=0;n<N;n++)
		printf("%d %s\n", age[n], name[n]);
	free(age);
	for(int n=0;n<N;n++)
		free(name[n]);
	free(name);
	return 0;
}