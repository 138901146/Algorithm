#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main(void)
{
	int N;
	char num[11]={'\0', };
	bool found=false;

	scanf("%d", &N);
	sprintf(num,"%d", N);

	for(int i=1;i<strlen(num);i++)
	{
		int num1=1, num2=1;

		for(int j=0;j<i;j++)
			num1*=num[j]-'0';
		for(int j=i;j<strlen(num);j++)
			num2*=num[j]-'0';

		if(num1==num2)
		{
			found=true;
			break;
		}
	}

	printf("%s\n", found?"YES":"NO");
	return 0;
}