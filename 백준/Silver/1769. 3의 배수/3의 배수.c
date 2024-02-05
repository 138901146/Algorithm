#include<stdio.h>

int sum=0, count=0, transfer=0;
char X[1000001]={'\0'};

int main(void)
{
	scanf("%s", X);

	for(transfer=0;X[transfer];++transfer)
		sum+=X[transfer]-48;

	while(sum>9)
	{
		int temp=sum;
		sum=0;
		++count;

		while(temp)
		{
			sum+=temp%10;
			temp/=10;
		}
	}

	printf("%d\n%s", count+(transfer!=1), sum%3?"NO":"YES");
	return 0;
}