#include<stdio.h>
#include<string.h>

int main(void)
{
	char N[601]={'\0', };
	int num=0, sum=0;

	fgets(N,sizeof(N),stdin);

	for(int n=0;n<strlen(N);n++)
		if(N[n]>='0' && N[n]<='9')
		{
			num*=10;
			num+=N[n]-'0';
		}
		else
		{
			sum+=num;
			num=0;
		}

	printf("%d\n", sum+num);
	return 0;
}