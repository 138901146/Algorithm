#include<stdio.h>
#include<string.h>

int main(void)
{
	int N, count=0, arr[10000]={0, };
	char num[1000000]={'\0', };

	scanf("%d", &N);

	for(int i=666;count<N;i++)
	{
    	num[0]='\0';

		sprintf(num,"%d",i);
		if(strstr(num,"666")!=NULL)
			arr[count++]=i;
	}

	printf("%d\n", arr[count-1]);

	return 0;
}