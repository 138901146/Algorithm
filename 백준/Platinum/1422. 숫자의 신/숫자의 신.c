#include<stdio.h>
#include<string.h>

char a_first[21]={'\0'}, b_first[21]={'\0'};

int compare(char *a,char *b)
{
	int len_a=strlen(a), len_b=strlen(b);

	if(len_a<len_b)
	{
		for(int i=0;i<len_b;++i)
			if(a[i%len_a]<b[i])
				return 1;
			else if(a[i%len_a]>b[i])
				return -1;
	}
	else
	{
		for(int i=0;i<len_a;++i)
			if(a[i]<b[i%len_b])
				return 1;
			else if(a[i]>b[i%len_b])
				return -1;
	}

	strcpy(a_first,a);
	strcat(a_first,b);
	strcpy(b_first,b);
	strcat(b_first,a);

	for(int i=0;i<len_a+len_b;++i)
		if(a_first[i]<b_first[i])
			return 1;
		else if(a_first[i]>b_first[i])
			return -1;

	return 1;
}

int main(void)
{
	int N, K, num, max=0;
	char list[50][11]={'\0'};

	scanf("%d%d", &K, &N);

	for(int k=0;k<K;++k)
	{
		scanf("%d", &num);
		max=num>max?num:max;
		sprintf(list[k],"%d", num);
	}
	for(int i=K;i<N;++i)
		sprintf(list[i],"%d", max);

	for(int i=0;i<N;++i)
		for(int j=i+1;j<N;++j)
			if(compare(list[i],list[j])>0)
			{
				char temp[11]={'\0'};
				strcpy(temp,list[i]);
				strcpy(list[i],list[j]);
				strcpy(list[j],temp);
			}

	for(int n=0;n<N;++n)
		printf("%s", list[n]);
	return 0;
}