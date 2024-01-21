#include<stdio.h>
#include<string.h>

int main(void)
{
	int len;
	char str[51]={'\0'}, ans[51]={'\0'};

	gets(str);
	len=strlen(str);

	for(int i=1;i<len;++i)
		for(int j=i+1;j<len;++j)
		{
			char temp[51]={'\0'};

			for(int k=0;k<i;++k)
				temp[i-k-1]=str[k];
			for(int k=i;k<j;++k)
				temp[i+j-k-1]=str[k];
			for(int k=j;k<len;++k)
				temp[j+len-k-1]=str[k];

			if(ans[0]=='\0' || strcmp(temp,ans)<0)
				strcpy(ans,temp);
		}

	puts(ans);
	return 0;
}