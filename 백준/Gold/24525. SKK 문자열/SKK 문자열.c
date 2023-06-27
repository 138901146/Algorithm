#include<stdio.h>
#include<malloc.h>
#include<string.h>

int main(void)
{
	char str[100001]={'\0', };
	int length, *SKK=NULL, max=0, *last=malloc(300001*sizeof(int)), count=0, *appeared=NULL;

	scanf("%s", str);
	length=strlen(str);
	SKK=(int *)calloc(length+1,sizeof(int));
	appeared=(int *)calloc(length+1,sizeof(int));

	for(int i=0;i<300001;i++)
		last[i]=-1;
	last[100000]=0;

	for(int i=0;i<length;i++)
		if(str[i]=='S')
		{
			appeared[i+1]=appeared[i]+1;
			SKK[i+1]=SKK[i]+2;
		}
		else if(str[i]=='K')
		{
			appeared[i+1]=appeared[i]+1;
			SKK[i+1]=SKK[i]-1;
		}
		else
		{
			appeared[i+1]=appeared[i];
			SKK[i+1]=SKK[i];
		}

	for(int i=1;i<=length;i++)
		if(last[SKK[i]+100000]<0)
			last[SKK[i]+100000]=i;
		else if(appeared[i]!=appeared[last[SKK[i]+100000]])
				max=(i-last[SKK[i]+100000])>max?i-last[SKK[i]+100000]:max;

	printf("%d\n", max==0?-1:max);
	free(SKK);
	free(appeared);
	free(last);
	return 0;
}