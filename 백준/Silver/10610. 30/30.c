#include<stdio.h>
#include<string.h>

int main(void)
{
	char N[100001]={'\0', };
	int count[10]={0, }, sum=0;

	scanf("%s", N);

	for(int i=0;i<strlen(N);i++)
		count[N[i]-'0']++;

	for(int i=1;i<10;i++)
		sum+=i*count[i];

	if(sum%3!=0 || count[0]==0)
		printf("-1\n");
	else
	{
		for(int i=9;i>=0;i--)
			for(int j=0;j<count[i];j++)
				printf("%d", i);
		printf("\n");
	}

	return 0;
}